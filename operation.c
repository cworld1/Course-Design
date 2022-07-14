#include "aircraft.h"

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
        printf("-> ���ڼ��غ�����Ϣ...\n");
        fscanf(fp, "%d", &(flights_p->length));
        for (int i = 0; i < flights_p->length; i++)
            fscanf(fp, "%d %s %s %s %s %s %s %d %d %s",
                   &(flights_p->flights[i].flight_id),
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
        printf("-> ����ͬ��������Ϣ...\n");
        fprintf(fp, "%d\n", flights_p->length);
        for (int i = 0; i < flights_p->length; i++)
            fprintf(fp, "%d %s %s %s %s %s %s %d %d %s\n",
                    flights_p->flights[i].flight_id,
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
    // ���
    /* for (int i = 0; i < flights_p->length; i++)
        printf("%s %s %s %s %s %s %d %d %s\n",
               flights_p->flights[i].no,
               flights_p->flights[i].dep_city,
               flights_p->flights[i].arr_city,
               flights_p->flights[i].date,
               flights_p->flights[i].dep_time,
               flights_p->flights[i].arr_time,
               flights_p->flights[i].price,
               flights_p->flights[i].remain,
               flights_p->flights[i].carrier); */
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
        printf("-> ���ڼ��ض�����Ϣ...\n");
        fscanf(fp, "%d", &(orders_p->length));
        for (int i = 0; i < orders_p->length; i++)
            fscanf(fp, "%s %d %d %s %s %s %s",
                   orders_p->orders[i].date,
                   &(orders_p->orders[i].id),
                   &(orders_p->orders[i].flight_id),
                   orders_p->orders[i].phone,
                   orders_p->orders[i].name,
                   orders_p->orders[i].type,
                   orders_p->orders[i].card_id);
    }
    else
    {
        printf("-> ���ڶ�ȡ������Ϣ...\n");
        fprintf(fp, "%d\n", orders_p->length);
        if (orders_p->length == 0)
            return;
        for (int i = 0; i < orders_p->length; i++)
            fprintf(fp, "%s %d %d %s %s %s %s\n",
                    orders_p->orders[i].date,
                    orders_p->orders[i].id,
                    orders_p->orders[i].flight_id,
                    orders_p->orders[i].phone,
                    orders_p->orders[i].name,
                    orders_p->orders[i].type,
                    orders_p->orders[i].card_id);
    }
    // ���
    /* for (int i = 0; i < orders_p->length; i++)
        printf("%s %d %d %s %s %s %s\n",
               orders_p->orders[i].date,
               orders_p->orders[i].id,
               orders_p->orders[i].flight_id,
               orders_p->orders[i].phone,
               orders_p->orders[i].name,
               orders_p->orders[i].type,
               orders_p->orders[i].card_id); */
    fclose(fp);
}

// ��ӡ������Ϣ�б�
void Print_Flights(Flights *flights_p, int *list, int length)
{
    printf("| Ϊ���ҵ���             |\n");
    printf("|����ID|�����|��������|�������| �������� |����ʱ��|����ʱ��|Ʊ��|ʣ��Ʊ��| ���չ�˾    \n");
    printf("|------|------|--------|--------|----------|--------|--------|----|--------|-------------\n");
    for (int i = 0; i < length; i++)
        printf("|  %4d|%6s|%8s|%8s|%10s|%8s|%8s|%4d|%8d|%-14s\n",
               flights_p->flights[list[i]].flight_id,
               flights_p->flights[list[i]].no,
               flights_p->flights[list[i]].dep_city,
               flights_p->flights[list[i]].arr_city,
               flights_p->flights[list[i]].date,
               flights_p->flights[list[i]].dep_time,
               flights_p->flights[list[i]].arr_time,
               flights_p->flights[list[i]].price,
               flights_p->flights[list[i]].remain,
               flights_p->flights[list[i]].carrier);
}