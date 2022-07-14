#include "aircraft.h"

// ���ݺ������
void Flights_Search(Flights *flights_p, int type)
{
    int list[flights_p->length], pos = 0;
    if (type == NO)
    {
        char input_no[10];
        printf(" -> ������Ҫ��ѯ�ĺ���ţ�");
        scanf("%s", &input_no);
        for (int i = 0; i < flights_p->length; i++)
            if (strcmp(flights_p->flights[i].no, input_no) == 0)
            {
                list[pos] = i;
                pos++;
            }
    }
    else if (type == CITY)
    {
        char input_dep[10], input_arr[10];
        printf("������������У�");
        scanf("%s", input_dep);
        printf("�����뵽����У�");
        scanf("%s", input_arr);
        for (int i = 0; i < flights_p->length; i++)
            if (strcmp(flights_p->flights[i].dep_city, input_dep) == 0 &&
                strcmp(flights_p->flights[i].dep_city, input_arr) == 0)
            {
                list[pos] = i;
                pos++;
            }
    }
    else
    {
        printf("�������\n");
        return;
    }
    if (pos == 0)
        printf("��������غ��࣡\n");
    else
    {
        printf("Ϊ���ҵ����º��ࣺ\n");
        Print_Flights(flights_p, list, pos);
    }
}

// ���Ҷ���
void Orders_Search(Orders *orders_p)
{
    int i, list[orders_p->length], pos = 0;
    char input_id[20];
    if (orders_p->length == 0)
    {
        printf("��ǰ��Ʊ����Ϊ0���޷���ѯ��\n");
        return;
    }
    printf("������֤���ţ�");
    scanf("%s", input_id);
    for (i = 0; i < orders_p->length; i++)
        if (strcmp(orders_p->orders[i].card_id, input_id) == 0)
        {
            list[pos] = i;
            pos++;
        }
    if (pos == 0)
        printf("��������ض���������ϸ�˶ԣ�\n");
    else
    {
        Print_Orders(orders_p, list, pos);
        printf("Ϊ���ҵ����¶�����\n");
    }
}

// ����Ҫ���������˵�
void Search(Flights *flights_p, Orders *orders_p)
{
    int input_key;
    printf("| 1.������Ϣ             |\n");
    printf("| 2.��Ʊ��Ϣ             |\n");
    printf(" -> ��ѡ���ѯ����");
    scanf("%d", &input_key);
    switch (input_key)
    {
    case 1:;
        int input_key2;
        printf("| 1.������Ų�ѯ         |\n");
        printf("| 2.���𽵳��в�ѯ       |\n");
        printf(" -> ��ѡ���ѯ��ʽ��");
        scanf("%d", &input_key2);
        printf(" ------------------------\n");
        Flights_Search(flights_p, input_key2);
        break;
    case 2:
        Orders_Search(orders_p);
        break;
    default:
        printf("��������!\n");
        break;
    }
}

// �Ƽ�����
void Recommend(Flights *flights_p, int num)
{
    int list[flights_p->length], pos = 0;
    printf("��Ǹ���ú������޿�����λ��");
    for (int i = 0; i < flights_p->length; i++)
        if ((strcmp(flights_p->flights[num].dep_city, flights_p->flights[i].dep_city) == 0) &&
            (strcmp(flights_p->flights[num].arr_city, flights_p->flights[i].arr_city) == 0) &&
            (i != num) &&
            (flights_p->flights[i].remain != 0))
        {
            list[pos] = i;
            pos++;
        }
    if (pos == 0)
    {
        printf("��ѡ���������ࡣ\n");
    }
    else
    {
        printf("Ϊ���ҵ����º��ࣺ\n");
        Print_Flights(flights_p, list, pos);
    }
}

// ��д������Ϣ&�洢
void Pay(Flights *flights_p, Orders *orders_p, int i)
{
    printf("������ͻ���Ϣ\n");
    // date
    time_t cur_time = time(NULL);
    strftime(
        orders_p->orders[orders_p->length].date,
        sizeof(orders_p->orders[orders_p->length].date),
        "%Y-%m-%d",
        localtime(&cur_time));
    // id
    srand((unsigned)time(NULL));
    orders_p->orders[orders_p->length].id = rand() * 787;
    // flight_id
    orders_p->orders[orders_p->length].flight_id = flights_p->flights[i].flight_id;
    // phone
    printf("��ϵ�绰��");
    scanf("%s", orders_p->orders[orders_p->length].phone);
    // name
    printf("�˿�������");
    scanf("%s", orders_p->orders[orders_p->length].name);
    // type
    printf("�˿����ͣ�����/��ͯ����");
    scanf("%s", orders_p->orders[orders_p->length].type);
    // card_id
    printf("֤�����룺");
    scanf("%s", orders_p->orders[orders_p->length].card_id);

    printf("��Ӧ֧��Ʊ��%dԪ\n", flights_p->flights[i].price);
    flights_p->flights[i].remain--;
    orders_p->length++;

    Open_Flights(flights_p, WRITE);
    Open_Orders(orders_p, WRITE);
    printf("��Ʊ�ɹ���\n");
}

// ����Ҫ����Ʊ�˵�
void Reserve(Flights *flights_p, Orders *orders_p)
{
    int i;
    int input_id;
    printf("������ҪԤ������ĺ���ID��");
    scanf("%d", &input_id);
    for (i = 0; i < flights_p->length; i++)
        if (flights_p->flights[i].flight_id == input_id)
            break;
    if (i == flights_p->length)
    {
        printf("�����ڸú���!\n");
        return;
    }
    if (flights_p->flights[i].remain == 0)
        Recommend(flights_p, i);
    else
        Pay(flights_p, orders_p, i);
}

// ����Ҫ����Ʊ�˵�
void Withdraw(Flights *flights_p, Orders *orders_p)
{
    FILE *fp1, *fp2;
    int k, i;
    char temp[20];
    if (orders_p->length == 0)
    {
        printf("��������\n");
        return;
    }
    printf("������ͻ�֤����\n");
    scanf("%s", temp);
    for (k = 0; k < orders_p->length; k++)
        if (strcmp(temp, orders_p->orders[k].card_id) == 0)
            break;
    if (k == orders_p->length)
    {
        printf("�ÿͻ������ڣ�\n");
        return;
    }
    for (i = 0; i < flights_p->length; i++)
        if (orders_p->orders[k].flight_id == flights_p->flights[i].flight_id)
            break;
    flights_p->flights[i].remain++;
    for (; k < orders_p->length - 1; k++)
        orders_p->orders[k] = orders_p->orders[k + 1];
    orders_p->length--;

    Open_Flights(flights_p, WRITE);
    Open_Orders(orders_p, WRITE);
    printf("��Ʊ�ɹ���\n");
}

// ����Ҫ�������˵�
void Feedback(Feedbacks *feedbacks_p)
{
    // date
    time_t cur_time = time(NULL);
    strftime(
        feedbacks_p->feedbacks[feedbacks_p->length].date,
        sizeof(feedbacks_p->feedbacks[feedbacks_p->length].date),
        "%Y-%m-%d",
        localtime(&cur_time));
    // name
    printf("����������");
    scanf("%s", feedbacks_p->feedbacks[feedbacks_p->length].name);
    // contact
    printf("������ϵ��ʽ������/�绰���룩��");
    scanf("%s", feedbacks_p->feedbacks[feedbacks_p->length].contact);
    // no
    printf("���������ĺ��ࣺ");
    scanf("%s", feedbacks_p->feedbacks[feedbacks_p->length].no);
    // content
    printf("���ķ������ݣ�");
    scanf("%s", feedbacks_p->feedbacks[feedbacks_p->length].content);
    feedbacks_p->length++;
    Open_Feedbacks(feedbacks_p, WRITE);
    printf("��л���ķ��������ķ������Ϊ���ǳ�����������������ĳ���������\n");
}