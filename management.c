#include "aircraft.h"

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