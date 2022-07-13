#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define m 40
#define n 100
enum way_of_open
{
    READ,
    WRITE
};

// ������Ϣ�ṹ��
typedef struct
{
    char no[10];
    char dep_city[10];
    char arr_city[10];
    char date[11];
    char dep_time[6];
    char arr_time[6];
    int price;
    int remain;
    char carrier[18];
} Flight_Info;

typedef struct
{
    Flight_Info flights[m];
    int length;
} Flights;

// ������Ϣ�ṹ��
typedef struct
{
    char date[10];
    int id;
    char no[10];
    int phone[11];
    char name[9];
    char type[6];
    char card_id[18];
} Order;

typedef struct
{
    Order orders[n];
    int length;
} Orders;

// ��ӡ��ӭ���
void Welcome()
{
    printf("**********************\n");
    printf("* ��ӭʹ�÷ɻ���Ʊϵͳ *\n");
    printf("**********************\n");
}

// ��ȡ/д�뺽����Ϣ
void Open_Flights(Flights *flights_p, int type)
{
    FILE *fp;
    if ((fp = fopen(
             "./src/flights_info.txt",
             (type == READ ? "r" : "w"))) == NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    if (type == READ)
    {
        printf("���ڼ��غ�����Ϣ...\n");
        fscanf(fp, "%d", &(flights_p->length));
        for (int i = 0; i < flights_p->length; i++)
            fscanf(fp, "%s %s %s %s %s %s %d %d %s",
                   flights_p->flights[i].no,
                   flights_p->flights[i].dep_city,
                   flights_p->flights[i].arr_city,
                   flights_p->flights[i].date,
                   flights_p->flights[i].dep_time,
                   flights_p->flights[i].arr_time,
                   &(flights_p->flights[i].price),
                   &(flights_p->flights[i].remain),
                   flights_p->flights[i].carrier);
    }
    else
    {
        printf("����ͬ��������Ϣ...\n");
        fprintf(fp, "%d\n", flights_p->length);
        for (int i = 0; i < flights_p->length; i++)
            fprintf(fp, "%s %s %s %s %s %s %d %d %s\n",
                    flights_p->flights[i].no,
                    flights_p->flights[i].dep_city,
                    flights_p->flights[i].arr_city,
                    flights_p->flights[i].date,
                    flights_p->flights[i].dep_time,
                    flights_p->flights[i].arr_time,
                    flights_p->flights[i].price,
                    flights_p->flights[i].remain,
                    flights_p->flights[i].carrier);
    }
    fclose(fp);
}

// ��ȡ/д�붩����Ϣ
void Open_Orders(Orders *orders_p, int type)
{
    FILE *fp;
    if ((fp = fopen(
             "./src/orders_info.txt",
             (type == READ ? "r" : "w"))) == NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    if (type == READ)
    {

        fscanf(fp, "%d", &(orders_p->length));
        for (int i = 0; i < orders_p->length; i++)
            fscanf(fp, "%s %d %s %d %s %s %s",
                   orders_p->orders[i].date,
                   &(orders_p->orders[i].id),
                   orders_p->orders[i].no,
                   &(orders_p->orders[i].phone),
                   orders_p->orders[i].name,
                   orders_p->orders[i].type,
                   orders_p->orders[i].card_id);
    }
    else
    {
        fprintf(fp, "%d\n", &(orders_p->length));
        if (orders_p->length == 0)
            return;
        for (int i = 0; i < orders_p->length; i++)
            fprintf(fp, "%s %d %s %d %s %s %s\n",
                    orders_p->orders[i].date,
                    orders_p->orders[i].id,
                    orders_p->orders[i].no,
                    orders_p->orders[i].phone,
                    orders_p->orders[i].name,
                    orders_p->orders[i].type,
                    orders_p->orders[i].card_id);
    }
    fclose(fp);
}

// ���ݺ������
void Flight_Search(Flights *flights_p)
{
    int i;
    char input_no[10];
    printf("������Ҫ��ѯ�ĺ���ţ�");
    scanf("%s", &input_no);
    for (i = 0; i < flights_p->length; i++)
        if (strcmp(flights_p->flights[i].no, input_no) == 0)
            break;
    if (i == flights_p->length)
        printf("�����ڸú���!\n");
    else
        printf("�ú�����Ϣ����:\n\
����ţ�%s\n\
�������У�%s\n\
������У�%s\n\
�������ڣ�%s\n\
����ʱ�䣺%s\n\
����ʱ�䣺%s\n\
Ʊ�ۣ�%d\n\
ʣ��Ʊ����%d\n\
���չ�˾��%s\n",
               flights_p->flights[i].no,
               flights_p->flights[i].dep_city,
               flights_p->flights[i].arr_city,
               flights_p->flights[i].date,
               flights_p->flights[i].dep_time,
               flights_p->flights[i].arr_time,
               flights_p->flights[i].price,
               flights_p->flights[i].remain,
               flights_p->flights[i].carrier);
}

// ����ʱ�����
void Time_Search(Flights *flights_p)
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
            printf("���������ĺ�����Ϣ����:\n\
����ţ�%s\n\
�������У�%s\n\
������У�%s\n\
�������ڣ�%s\n\
����ʱ�䣺%s\n\
����ʱ�䣺%s\n\
Ʊ�ۣ�%d\n\
ʣ��Ʊ����%d\n\
���չ�˾��%s\n",
                   flights_p->flights[i].no,
                   flights_p->flights[i].dep_city,
                   flights_p->flights[i].arr_city,
                   flights_p->flights[i].date,
                   flights_p->flights[i].dep_time,
                   flights_p->flights[i].arr_time,
                   flights_p->flights[i].price,
                   flights_p->flights[i].remain,
                   flights_p->flights[i].carrier);
        }
}

// ���Һ���˵�
void Flights_Search_Menu(Flights *flights_p)
{
    int input_key;
    printf("��ѡ���ѯ��ʽ\n");
    printf("* 1-------------������Ų�ѯ *\n");
    printf("* 2-------------���𽵳��в�ѯ *\n");
    scanf("%d", &input_key);
    switch (input_key)
    {
    case 1:
        Flight_Search(flights_p);
        break;
    case 2:
        Time_Search(flights_p);
        break;
    default:
        printf("��������!\n");
        break;
    }
}

// ���Ҷ���&�˵�
void Orders_Search(Orders *orders_p)
{
    int i;
    char input_id[20];
    if (orders_p->length == 0)
    {
        printf("��ǰ��Ʊ����Ϊ0,�޷���ѯ!\n");
        return;
    }
    printf("������֤���ţ�");
    scanf("%s", input_id);
    for (i = 0; i < orders_p->length; i++)
        if (strcmp(orders_p->orders[i].card_id, input_id) == 0)
            break;
    if (i == orders_p->length)
        printf("�����ڸÿͻ�!\n");
    else
        printf("�ÿͻ���Ϣ����:\n\
��Ʊʱ�䣺%s\n\n\
�����ţ�%d\n\n\
����ţ�%s\n\n\
��ϵ�绰��%d\n\n\
�˿�������%s\n\n\
�˿����ͣ�%s\n\n\
֤�����룺%s\n\n",
               orders_p->orders[i].date,
               orders_p->orders[i].id,
               orders_p->orders[i].no,
               orders_p->orders[i].phone,
               orders_p->orders[i].name,
               orders_p->orders[i].type,
               orders_p->orders[i].card_id);
}

// ����Ҫ���������˵�
void Search(Flights *flights_p, Orders *orders_p)
{
    int input_key;
    printf("��ѡ���ѯ����\n");
    printf("* 1-------------������Ϣ *\n");
    printf("* 2-------------��Ʊ��Ϣ *\n");
    scanf("%d", &input_key);
    switch (input_key)
    {
    case 1:
        Flights_Search_Menu(flights_p);
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
void Recommend(Flights *flights_p, int i)
{
    printf("��Ǹ���ú������޿�����λ\n");
    for (int j = 0; j < flights_p->length; j++)
        if ((strcmp(flights_p->flights[i].dep_city, flights_p->flights[j].dep_city) == 0) && (j != i) && (flights_p->flights[j].remain != 0))
        {
            printf("����ѡ������ƺ��ࣺ\n\
����ţ�%s\n\
�������У�%s\n\
������У�%s\n\
�������ڣ�%s\n\
����ʱ�䣺%s\n\
����ʱ�䣺%s\n\
Ʊ�ۣ�%d\n\
ʣ��Ʊ����%d\n\
���չ�˾��%s\n",
                   flights_p->flights[i].no,
                   flights_p->flights[i].dep_city,
                   flights_p->flights[i].arr_city,
                   flights_p->flights[i].date,
                   flights_p->flights[i].dep_time,
                   flights_p->flights[i].arr_time,
                   flights_p->flights[i].price,
                   flights_p->flights[i].remain,
                   flights_p->flights[i].carrier);
        }
}

// ��д������Ϣ&�洢
void Pay(Flights *flights_p, Orders *orders_p, int i)
{
    printf("������ͻ���Ϣ\n");
    time_t cur_time = time(NULL);
    strftime(
        orders_p->orders[orders_p->length].date,
        sizeof(orders_p->orders[orders_p->length].date) - 1,
        "%Y-%m-%d",
        localtime(&cur_time));
    printf("��ϵ�绰��");
    scanf("%s", orders_p->orders[orders_p->length].phone);
    printf("�˿�������");
    scanf(" %s", orders_p->orders[orders_p->length].name);
    printf("�˿����ͣ�����/��ͯ����");
    scanf(" %s", orders_p->orders[orders_p->length].type);
    printf("֤�����룺");
    scanf(" %s", orders_p->orders[orders_p->length].card_id);
    strcpy(flights_p->flights[i].no, orders_p->orders[orders_p->length].no);

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
    char input_no[10];
    printf("������ҪԤ������ĺ����\n");
    scanf("%s", &input_no);
    for (i = 0; i < flights_p->length; i++)
        if (strcmp(flights_p->flights[i].no, input_no) == 0)
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

// ��Ʊ�˵�
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
        if (orders_p->orders[k].no == flights_p->flights[i].no)
            break;
    flights_p->flights[i].remain++;
    for (; k < orders_p->length - 1; k++)
        orders_p->orders[k] = orders_p->orders[k + 1];
    orders_p->length--;

    Open_Flights(flights_p, WRITE);
    Open_Orders(orders_p, WRITE);
    printf("��Ʊ�ɹ���\n");
}
/*
void Fadd(Flights *flights_p)
{
    FILE *fp1;
    int i;
    printf("����������������Ϣ\n");
    printf("�����\n");
    scanf("%d", &(flights_p->flight[flights_p->length].no));
    printf("��ʱ��\n");
    scanf(" %s", flights_p->flight[flights_p->length].date);
    printf("�𽵳���\n");
    scanf(" %s", flights_p->flight[flights_p->length].dep_city);
    printf("Ʊ��\n");
    scanf("%d", &(flights_p->flight[flights_p->length].price));
    printf("Ʊ���ۿ�\n");
    scanf("%d", &(flights_p->flight[flights_p->length].discount));
    printf("������λ��\n");
    scanf("%d", &(flights_p->flight[flights_p->length].remain));
    flights_p->length++;
    if ((fp1 = fopen("./src/flights_info.txt", "w")) == NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    fprintf(fp1, "%d\n", flights_p->length);
    for (i = 0; i < flights_p->length; i++)
        fprintf(fp1, "%d %s %s %d %d %d\n", flights_p->flights[i].no, flights_p->flights[i].date, flights_p->flights[i].dep_city, flights_p->flights[i].price, flights_p->flights[i].discount, flights_p->flights[i].remain);
    fclose(fp1);
}
void Fcan(Flights *flights_p)
{
    FILE *fp1;
    int i, t;
    printf("������Ҫȡ������ĺ����\n");
    scanf("%d", &t);
    for (i = 0; i < flights_p->length; i++)
        if (flights_p->flights[i].no == t)
            break;
    if (i == flights_p->length)
    {
        printf("�����ڸú���!\n");
        return;
    }
    for (; i < flights_p->length - 1; i++)
        flights_p->flights[i] = flights_p->flight[i + 1];
    flights_p->length--;
    if ((fp1 = fopen("./src/flights_info.txt", "w")) == NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    fprintf(fp1, "%d\n", flights_p->length);
    for (i = 0; i < flights_p->length; i++)
        fprintf(fp1, "%d %s %s %d %d %d\n", flights_p->flights[i].no, flights_p->flights[i].date, flights_p->flights[i].dep_city, flights_p->flights[i].price, flights_p->flights[i].discount, flights_p->flights[i].remain);
    fclose(fp1);
}
void Fchg(Flights *flights_p)
{
    FILE *fp1;
    int i, t;
    printf("������Ҫ�޸ĺ���ĺ����\n");
    scanf("%d", &t);
    for (i = 0; i < flights_p->length; i++)
        if (flights_p->flights[i].no == t)
            break;
    if (i == flights_p->length)
    {
        printf("�����ڸú���!\n");
        return;
    }
    printf("�������µ���ʱ��\n");
    scanf("%s", flights_p->flights[i].date);
    printf("�������µ�Ʊ��\n");
    scanf("%d", &(flights_p->flights[i].price));
    printf("�������µ�Ʊ���ۿ�\n");
    scanf("%d", &(flights_p->flights[i].discount));
    if ((fp1 = fopen("./src/flights_info.txt", "w")) == NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    fprintf(fp1, "%d\n", flights_p->length);
    for (i = 0; i < flights_p->length; i++)
        fprintf(fp1, "%d %s %s %d %d %d\n", flights_p->flights[i].no, flights_p->flights[i].date, flights_p->flights[i].dep_city, flights_p->flights[i].price, flights_p->flights[i].discount, flights_p->flights[i].remain);
    fclose(fp1);
}
void Adjust(Flights *flights_p)
{
    int k;
    printf("��ѡ��Ҫִ�еĹ���\n");
    printf("1---------���Ӻ���\n");
    printf("2---------ȡ������\n");
    printf("3---------�Ķ���Ϣ\n");
    scanf("%d", &k);
    switch (k)
    {
    case 1:
        Fadd(flights_p);
        break;
    case 2:
        Fcan(flights_p);
        break;
    case 3:
        Fchg(flights_p);
        break;
    }
} */