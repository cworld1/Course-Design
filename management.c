#include "aircraft.h"

// ��������
void Add_Flight(Flights *flights_p)
{
    printf("����������������Ϣ\n");
    printf("����ID��");
    scanf("%d", &(flights_p->flights[flights_p->length].flight_id));
    printf("����ţ�");
    scanf("%s", flights_p->flights[flights_p->length].no);
    printf("�������У�");
    scanf(" %s", flights_p->flights[flights_p->length].dep_city);
    printf("������У�");
    scanf(" %s", flights_p->flights[flights_p->length].arr_city);
    printf("�������ڣ�");
    scanf(" %s", flights_p->flights[flights_p->length].date);
    printf("����ʱ�䣺");
    scanf(" %s", flights_p->flights[flights_p->length].dep_time);
    printf("����ʱ�䣺");
    scanf(" %s", flights_p->flights[flights_p->length].arr_time);
    printf("Ʊ�ۣ�");
    scanf("%d", &(flights_p->flights[flights_p->length].price));
    printf("ʣ��Ʊ����");
    scanf("%d", &(flights_p->flights[flights_p->length].remain));
    printf("���չ�˾��");
    scanf(" %s", flights_p->flights[flights_p->length].carrier);
    flights_p->length++;
    Open_Flights(flights_p, WRITE);
}

// ȡ������
void Modify_Flight(Flights *flights_p, int type)
{
    int i, input_id;
    printf("������Ҫȡ������ĺ���ID��");
    scanf("%d", &input_id);
    for (i = 0; i < flights_p->length; i++)
        if (flights_p->flights[i].flight_id == input_id)
            break;
    if (i == flights_p->length)
    {
        printf("�����ڸú��࣡\n");
        return;
    }

    if (type == CANCEL)
    {
        for (; i < flights_p->length - 1; i++)
            flights_p->flights[i] = flights_p->flights[i + 1];
        flights_p->length--;
    }
    else if (type == EDIT)
    {
        printf("�������ڣ�");
        scanf(" %s", flights_p->flights[i].date);
        printf("����ʱ�䣺");
        scanf(" %s", flights_p->flights[i].dep_time);
        printf("����ʱ�䣺");
        scanf(" %s", flights_p->flights[i].arr_time);
        printf("Ʊ�ۣ�");
        scanf("%d", &(flights_p->flights[i].price));
    }
    Open_Flights(flights_p, WRITE);
}

//����Ա��¼
int Admin_Login()
{
    char password[20], encrypted[20], key;

    // ���ļ�
    FILE *fp;
    if ((fp = fopen("./src/admin.txt", "r")) == NULL)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(0);
    }
    fscanf(fp, "%s", encrypted);
    fclose(fp);

    // ����
    printf("-> ���������Ա���룺");
    for (int i = 0; (key = getch()) != '\r'; i++)
    {
        if (key >= 'A' && key <= 'Z')
            password[i] = ((key - 'A') + MOVE) % 26 + 'A';
        else if (key >= 'a' && key <= 'z')
            password[i] = ((key - 'a') + MOVE) % 26 + 'a';
        else
            password[i] = key;
        putchar('*');
    }

    // �ȶ�
    if (strcmp(password, encrypted) == 0)
    {
        printf("\n��֤�ɹ���\n");
        return PASSED;
    }
    printf("\n��֤ʧ�ܣ�\n");
    return FAILED;
}

// ����Ҫ������˵�
void Adjust(Flights *flights_p, Feedbacks *feedbacks_p)
{
    if (Admin_Login() == FAILED)
        return;
    int choose;
    printf("| 1.���Ӻ���             |\n");
    printf("| 2.ȡ������             |\n");
    printf("| 3.�Ķ�������Ϣ         |\n");
    printf("| 4.�鿴������Ϣ         |\n");
    printf("-> ��ѡ��Ҫִ�еĹ��ܣ�");
    scanf("%d", &choose);
    printf(" ------------------------\n");
    switch (choose)
    {
    case 1:
        Add_Flight(flights_p);
        break;
    case 2:
        Modify_Flight(flights_p, CANCEL);
        break;
    case 3:
        Modify_Flight(flights_p, EDIT);
        break;
    case 4:
        Print_Feedbacks(feedbacks_p);
        break;
    default:
        printf("��������!\n");
        return;
    }
}