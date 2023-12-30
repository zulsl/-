//通讯录是一个可以记录亲人、好友信息的工具。
//利用C++来实现一个通讯录管理系统
// 系统中需要实现的功能如下：
// 1、添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
// 2、显示联系人：显示通讯录中所有联系人信息
// 3、删除联系人：按照姓名进行删除指定联系人
// 4、查找联系人：按照姓名查看指定联系人信息
// 5、修改联系人：按照姓名重新修改指定联系人
// 6、清空联系人：清空通讯录中所有信息
// 0、退出通讯录：退出当前使用的通讯录
//
#include <iostream>
using namespace std;
#define MAX 1000

//封装函数显示该菜单 如 void showMenu()
//菜单界面
void showMenu()
{
    cout << "*************************" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出通讯录 *****" << endl;
    cout << "*************************" << endl;

}

//添加联系人实现步骤：
// 设计联系人结构体
// 设计通讯录结构体
// main函数中创建通讯录
// 封装添加联系人函数
// 测试添加联系人功能

//设计联系人结构体
struct lianxiren
{
    string name;//姓名
    string sex;//性别：1.男  2.女
    int age;//年龄
    string phone;//电话
    string addr;//住址
};

//设计通讯录结构体
struct tongxunlu
{
    lianxiren arr[MAX];//联系人数组
    int size=0;//联系人个数，初始化为0,每次添加联系人时加1 
};

//封装添加联系人函数
void tianjia(tongxunlu * txl)
{
    if (txl->size == (MAX-1))//判断通讯录是否达到上限//实际只能存储999个人
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        //姓名
        cout << "请输入姓名：" << endl;
        cin >> txl->arr[txl->size].name;
        //性别
        cout << "请输入性别：（男|女）" << endl;
        while (1)
        {
            cin >> txl->arr[txl->size].sex;//如果使用int类型，当输入的数据类型与预期不符时
                                           //cin会产生错误，并导致程序崩溃
                                           //可以使用以下语句来清除错误
                                           //cin.clear();
                                           //cin.ignore();
            if (txl->arr[txl->size].sex == "男" || txl->arr[txl->size].sex == "女")
            {
                break;//如果输入对了退出循环
            }
            else
            {
                cout << "你输入的信息不正确,请重新输入" << endl;//输入错了提示
                
            }
        }
        //年龄
        cout << "请输入年龄：" << endl;
        cin >> txl->arr[txl->size].age;
        cin.clear();
        cin.ignore();
        //电话
        cout << "请输入电话：" << endl;
        cin >> txl->arr[txl->size].phone;
        //住址
        cout << "请输入地址：" << endl;
        cin >> txl->arr[txl->size].addr;
        cout << "添加成功" << endl;
        txl->size++;//添加完毕联系人数量加1
        system("pause");    //请按任意键继续
        system("cls");//清屏操作
    }
}

//封装查看联系人函数
void xianshi(tongxunlu * txl)
{
    if (txl->size==0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < txl->size; i++)//遍历联系人数组
        {
            cout << "姓名：";
            cout << txl->arr[i].name << "\t";
            cout << "性别：";
            cout << txl->arr[i].sex << "\t";
            cout << "年龄：";
            cout << txl->arr[i].age << "\t";
            cout << "电话：";
            cout << txl->arr[i].phone << "\t";
            cout << "住址：";
            cout << txl->arr[i].addr << "\t";
            cout << endl;
        }
    }
    system("pause");    //请按任意键继续
    system("cls");//清屏操作
}

//封装一个函数，查找联系人是否存在
//检测联系人是否存在，如果存在，返回联系人所在数组中的位置，如果不存在，返回-1
int jiancha(tongxunlu* txl,string name)
{
    for (int i = 0; i < txl->size; i++)//遍历联系人数组
    {
        if (txl->arr[i].name == name)
        {
            return i;//如果找到返回联系人在数组中的位置
        }
    }
    return -1;/*    ！！！！！如果返回值写在循环里面，如果没有联系人而不执行循环，
                    会导致没有返回值，而且vs不会提醒，返回一个随机的值69！！！！！    */
}

//封装删除函数
void shanchu(tongxunlu * txl)
{
    cout << "请输入你要删除的联系人：" << endl;
    string name;
    cin >> name;
    int temp = jiancha(txl, name);//调用检测函数，接收检测函数返回的值
    if (temp == -1)//找不到此人
    {
        cout << "联系人不存在" << endl;
    }
    else//删除操作
    {
        for (int i = temp;i < txl->size; i++)//从联系人在数组中的位置开始
        {
            txl->arr[i] = txl->arr[i + 1];//让数组每一个元素前移
        }
        txl->size--;//数组数量减一
        cout << "删除成功" << endl;
    }
    system("pause");//请按任意键继续
    system("cls");//清屏操作
    return;//system必须写在return之前
}

//封装查找函数
void chazhao(tongxunlu * txl)
{
    cout << "请输入你要查找的姓名：" << endl;
    string name;
    cin >> name;
    int a = jiancha(txl, name);//调用检测函数，检测联系人是否存在
    if (a == -1)//如果为-1，则不存在
    {
        cout << "联系人不存在" << endl;//
    }
    else
    {
        cout << "姓名：" << txl->arr[a].name << "\t";
        cout << "性别：" << txl->arr[a].sex << "\t";
        cout << "年龄：" << txl->arr[a].age << "\t";
        cout << "电话：" << txl->arr[a].phone << "\t";
        cout << "住址：" << txl->arr[a].addr << "\t";
        cout << endl;
    }
    system("pause");//请按任意键继续
    system("cls");//清屏操作

}

//封装修改联系人函数
void xiugai(tongxunlu * txl)
{
    cout << "请输入联系人姓名：" << endl;
    string name;
    cin >> name;
    int a=jiancha(txl, name); //调用检查函数，检查联系人是否存在
    if (a == -1)
    {
        cout << "联系人不存在" << endl;
    }
    else
    {
        cout << "姓名：" << txl->arr[a].name << "\t";
        cout << "性别：" << txl->arr[a].sex << "\t";
        cout << "年龄：" << txl->arr[a].age << "\t";
        cout << "电话：" << txl->arr[a].phone << "\t";
        cout << "住址：" << txl->arr[a].addr << "\n";
        cout << "请输入你要更改的选项：\n1.姓名 2.性别 3.年龄 4.电话 5.住址" << endl;
        int x;
        cin >> x;
        switch (x)
        {
            case 1:
            {
                cout << "请输入修改后的联系人姓名：" << endl;
                string Xname;
                cin >> Xname;
                txl->arr[a].name = Xname;
            }
            break;
            case 2:
            {
                cout << "请输入修改后的联系人性别：" << endl;
                string Xsex;
                cin >> Xsex;
                txl->arr[a].sex = Xsex;
            }
            break;
            case 3:
            {
                cout << "请输入修改后的联系人年龄：" << endl;
                int Xage;
                cin >> Xage;
                txl->arr[a].age = Xage;
            }
                break;
            case 4:
            {
                cout << "请输入修改后的联系人电话：" << endl;
                string Xphone;
                cin >> Xphone;
                txl->arr[a].phone = Xphone;
            }
                break;
            case 5:
            {
                cout << "请输入修改后的联系人地址：" << endl;
                string Xaddr;
                cin >> Xaddr;
                txl->arr[a].addr = Xaddr;
            }
                break;
            default:
            {
                cout << "输入错误，请重新输入" << endl;
                system("pause");//请按任意键继续
                system("cls");//清屏操作
            }
            break;
        }
        cout << "修改成功" << endl;
    }
    system("pause");//请按任意键继续
    system("cls");//清屏操作
}

void qingkong(tongxunlu * txl)
{
    cout << "是否清空所有联系人：\n1.是 2.否" << endl;
    int x;
    cin >> x;
    if (x == 1)
    {
        txl->size = 0;
        cout << "通讯录已清空" << endl;
    }
    system("pause");//请按任意键继续
    system("cls");//清屏操作

}

int main()
{
    //创建通讯录变量
    tongxunlu txl; 
    int xuanze = 0;
    while (1)
    {
        showMenu();
        cin >> xuanze;
        switch (xuanze)
        {
        case 1:         //添加联系人
            tianjia(&txl);
            break;
        case 2:         //显示联系人
            xianshi(&txl);
            break;
        case 3:         //删除联系人
            shanchu(&txl);
            break;
        case 4:         //查找联系人
            chazhao(&txl);
            break;
        case 5:         //修改联系人
            xiugai(&txl);
            break;
        case 6:         //清空联系人
            qingkong(&txl);
            break;
        case 0:         //退出通讯录
            cout << "退出成功" << endl;
            system("pause");    //请按任意键继续
            return 0;           //退出当前函数
            break;

        default:
            {
                cout << "输入错误，请重新输入" << endl;
                system("pause");//请按任意键继续
                system("cls");//清屏操作
            }
            break;
        }
    }
    system("pause");//请按任意键继续
    return 0;
}
