#include <unistd.h>
#include "aircraft.h"

void main()
{
    int choose;
    Flights flights;
    Orders orders;
    Feedbacks feedbacks;
    chdir("D:/Project/C-Project/Course-Design/");
    // system("cls");
    printf("����������������������������������������������������\n");
    printf("��  ��ӭʹ�÷ɻ���Ʊϵͳ  ��\n");
    printf("����������������������������������������������������\n");
    flights.length = 0;
    orders.length = 0;
    feedbacks.length = 0;
    Open_Flights(&flights, READ);
    Open_Orders(&orders, READ);
    Open_Feedbacks(&feedbacks, READ);
    do
    {
        printf("����������������������������������������������������\n");
        printf("�� 1.��ѯ       2.��Ʊ    ��\n");
        printf("�� 3.��Ʊ       4.����    ��\n");
        printf("�� 5.��̨����             ��\n");
        printf("�� 6.�˳�                 ��\n");
        printf("��-> ������˵���ţ�");
        scanf("%d", &choose);
        printf("����������������������������������������������������\n");
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
        case 4:
            Feedback(&feedbacks);
            break;
        case 5:
            Adjust(&flights, &feedbacks);
            break;
        case 6:
            printf("��л����ʹ�á�������ʹ�����⣬���µ磺10086\n");
            break;
        default:
            printf("�޴˹��ܣ����������룡\n");
            break;
        }
        system("pause");
        system("cls");
    } while (choose != 6);
}