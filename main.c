#include <unistd.h>
#include "aircraft.h"

int main()
{
    int choose;
    Flights flights;
    Orders orders;
    system("cls");
    printf(" ------------------------\n");
    printf("|  ��ӭʹ�÷ɻ���Ʊϵͳ  |\n");
    printf(" ------------------------\n");
    flights.length = 0;
    orders.length = 0;
    Open_Flights(&flights, READ);
    chdir("D:/Project/C-Project/Course-Design/");
    Open_Orders(&orders, READ);
    do
    {
        printf(" ------------------------\n");
        printf("| 1.��ѯ  2.��Ʊ  3.��Ʊ |\n");
        printf("| 4.�޸ģ����޹���Ա��   |\n");
        printf("| 5.�˳�                 |\n");
        printf(" -> ������˵���ţ�");
        scanf("%d", &choose);
        printf(" ------------------------\n");
        switch (choose)
        {
        case 1:
            Search(&flights, &orders);
            break;
        case 2:
            Reserve(&flights, &orders);
            break;
        case 3:
            Withdraw(&flights, &orders);
            break;
        // case 4:
        //     Adjust(&flights);
        //     break;
        case 5:
            break;
        default:
            printf("\t�޴˹��ܣ�����������!\n");
            break;
        }
        system("pause");
        system("cls");
    } while (choose != 5);
}