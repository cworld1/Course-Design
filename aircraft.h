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
enum way_of_find
{
    NO = 1,
    CITY
};

// ������Ϣ�ṹ��
typedef struct
{
    int flight_id;
    char no[11];
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
    char date[11];
    int id;
    int flight_id;
    char phone[12];
    char name[10];
    char type[7];
    char card_id[19];
} Order_Info;

typedef struct
{
    Order_Info orders[n];
    int length;
} Orders;

// �ļ�/��Ļ��ӡ������أ�operation.c��
void Open_Flights(Flights *flights_p, int type);
void Open_Orders(Orders *orders_p, int type);
void Print_Flights(Flights *flights_p, int *list, int length);

// �ɻ�������أ�aircraft.c��
void Flights_Search(Flights *flights_p, int type);
void Orders_Search(Orders *orders_p);
void Search(Flights *flights_p, Orders *orders_p);

void Recommend(Flights *flights_p, int i);
void Pay(Flights *flights_p, Orders *orders_p, int i);
void Reserve(Flights *flights_p, Orders *orders_p);
void Withdraw(Flights *flights_p, Orders *orders_p);
