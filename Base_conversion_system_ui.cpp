//Base_conversion_system_ui
//g++ Base_conversion_system_ui.cpp -o ui
//编译指南：此程序仅可在visual studio的2019及以上版本编译器正常编译，
//无论是eclipse还是vs code亦或者是mingw编译器均会编译有错误，在处理
//pow()函数时，当值从int转为long long int时会有1点精度损失
//重写并禁止原pow函数时，可以再大多数平台使用
#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>//import system
//#include <cmath>
#define dateYear 2020
#define datemonth 12
#define day_releaseDayTime 4
#define auther_contact "bethaniebell8474@gmail.com"
#define auther_website "http://www.basicconstruction.cn/"
#define on "on"
#define off "off"
#define error1 "要转化的数字的格式不符合要求"
#define error2 "要转化的数字中的数字只能小于原本进制数"
#define system_ui "Base Conversion System GUI"
using namespace std;
long long int pow(int base, int index);
void write_in_str(string text, int x, int y);
void write_in_num(int Number, int x, int y);
void write_in_str(long long int NumberN, int x, int y);
void write_in_bool(bool signal, int x, int y);
bool get();
void default_start(int count_right, int count_error);
void pre_start();
void main_math_window();
//void get_data_co_windows();
//void get_current_bits();
void screen_one();
void screen_two();
void screen_three();
void screen_four();
void screen_five();
void screen_six();
void screen_seven();
void screen_eight();
void global_fullscreen_erase();
void erase_write(int times = 20);
void erase_lines(int lines, int x, int y);
void basic_screen();
void time_control(long time_elapsed);
void time_control_continue(long time_elapsed);
long long int reconvert_bits(string complex_d, int bits);
int base(char c);
string convertbits(long long int convert, int bits);
string convert_number_to_string(int multi_bit);
int error_judge(string complex_d, int previous_bits);
int main(void) {
    system("mode con cols=230 lines=60");
    pre_start();
    bool willrun = true;
    bool error_check;
    int continue_check;
    string complex_d;
    int previous_bits;
    int current_bits;
    int count_right = 0;
    int count_error = 0;
    default_start(count_right, count_error);
    while (willrun) {
        //get_data_co_windows();
        write_in_str("请输入原来数的进制,2-36", 30, 23);
        write_in_str("", 30, 24);
        cin >> previous_bits;
        write_in_str(previous_bits, 40, 12);
        erase_lines(2, 0, 23);
        write_in_str("请输入你要转化的数字", 30, 23);
        write_in_str("", 30, 24);
        cin >> complex_d;
        write_in_str(complex_d, 75, 12);
        erase_lines(2, 0, 23);
        write_in_str("we are examing if there is or not error....", 30, 23);
        time_control_continue(1);
        if (error_judge(complex_d, previous_bits) == 1) {
            write_in_str(error1, 40, 20);
            error_check = false;
        }
        else if (error_judge(complex_d, previous_bits) == 2) {
            write_in_str(error2, 40, 21);
            error_check = false;
        }
        else if (error_judge(complex_d, previous_bits) == 3) {
            write_in_str(error1, 40, 20);
            write_in_str(error2, 40, 21);
        }
        else {
            write_in_str("All right!", 30, 23);
            error_check = true;
        }
        if (error_check) {
            erase_lines(2, 0, 23);
            write_in_str("请输入你要转化的进制2-36", 30, 23);
            write_in_str("", 30, 24);
            cin >> current_bits;
            write_in_str(current_bits, 47, 17);
            write_in_str(convertbits(reconvert_bits(complex_d, previous_bits), current_bits), 80, 17);
            count_right = count_right + 1;
        }
        else {
            //do nothing
            willrun = true;
            count_error = count_error + 1;
        }
        default_start(count_right, count_error);//提前刷新面板
        erase_lines(2, 0, 23);
        write_in_str("想要继续吗(输入非零数字以继续)?", 30, 23);
        write_in_str("", 30, 25);
        cin >> continue_check;
        if (continue_check) {
            global_fullscreen_erase();
            default_start(count_right,count_error);
        }
        else {
            willrun = false;
        }
    }
}

void default_start(int count_right,int count_error) {
    main_math_window();
    write_in_str("转化成功次数", 87, 9);
    write_in_str(count_right, 100, 9);//这里用的是覆写型改值，（没必要先擦除再重写）
    write_in_str("不符转化要求", 87, 10);
    write_in_str(count_error, 100, 10);//这里用的是覆写型改值，（没必要先擦除再重写）
    //get();
}
void pre_start() {
    screen_one();
    time_control(1);
    screen_two();
    time_control(1);
    screen_three();
    time_control(1);
    screen_four();
    time_control(1);
    screen_five();
    time_control(1);
    screen_six();
    time_control(1);
    screen_seven();
    time_control(1);
    screen_eight();
    time_control(1);

}
void main_math_window() {
    basic_screen();
    write_in_str(on, 80, 9);
    write_in_str("原本进制数", 30, 12);
    write_in_str("原本的数字", 63, 12);
    write_in_str("要转化的进制数", 30, 17);
    write_in_str("转化成功的数字", 63, 17);
    write_in_str("报错信息", 30, 20);

}
//下面这段代码已经放置到main函数中
/*void get_data_co_windows(){
    write_in_str("请输入原来数的进制,2-36",30,23);
    write_in_str("",30,24);
    cin>>previous_bits;
    write_in_str(previous_bits,40,12);
    erase_lines(2,0,23);
    write_in_str("请输入你要转化的数字",30,23);
    write_in_str("",30,24);
    cin>>complex_d;
    write_in_str(complex_d,75,12);
    erase_lines(2,0,23);
    write_in_str("we are examing if there is or not error....",30,23);
}*/
/*
void get_current_bits(){
    erase_lines(2,0,23);
    write_in_str("请输入你要转化的进制2-36",30,23);
    write_in_str("",30,24);
    cin>>current_bits;
}*/
void screen_one() {
    basic_screen();
    write_in_str("正在加载资源文件。。。。", 57, 13);
}
void screen_two() {
    basic_screen();
    write_in_str("正在与本地服务器尝试连接(0/3)", 53, 13);
}
void screen_three() {
    basic_screen();
    write_in_str("连接本地服务器成功(1/3)", 57, 13);
}
void screen_four() {
    basic_screen();
    write_in_str("正在请求内存(1/3)", 53, 13);
}
void screen_five() {
    basic_screen();
    write_in_str("获得1024KB内存(2/3)", 53, 13);
}
void screen_six() {
    basic_screen();
    write_in_str("正在进行主程序初始化(2/3)", 53, 13);
}
void screen_seven() {
    basic_screen();
    write_in_str("初始化成功(3/3)", 53, 13);
}
void screen_eight() {
    basic_screen();
    write_in_str("All done, enjoy!", 53, 13);
}
void global_fullscreen_erase() {
    write_in_str("", 0, 0);
    for (int j = 0; j < 50; j++) {
        write_in_str("", 0, j);
        for (int i = 0; i < 126; i++) {
            cout << " ";
        }
    }
    write_in_str("", 0, 0);
}
void erase_write(int times) {
    for (int j = 0; j < times; j++) {
        cout << " ";
    }
}
void erase_lines(int lines, int x, int y) {
    write_in_str("", x, y);
    for (int j = 0; j < lines; j++) {
        write_in_str("", 0, y + j);
        for (int i = 0; i < 126; i++) {
            cout << " ";
        }
    }
}
void basic_screen() {
    write_in_str("", 0, 0);
    for (int i = 0; i < 126; i++) {
        cout << "-";
    }
    for (int i = 1; i < 5; i++) {
        write_in_str("[", 0, i);
        write_in_str("]", 125, i);
    }
    write_in_str("university: HenNan University", 90, 1);
    write_in_str(system_ui, 51, 2);
    write_in_str("auther: Wang Chenxu", 90, 2);
    write_in_str("contact:bethaniebell8474@gmail.com", 90, 3);
    write_in_str("", 0, 4);
    for (int i = 0; i < 126; i++) {
        cout << "-";
    }
}
void time_control(long time_elapsed) {
    long start_time = time(0);
    long end_time = time(0);
    long elapsed_time = end_time - start_time;
    while (elapsed_time < time_elapsed) {
        end_time = time(0);//write_in_str(" ",40,40);
        elapsed_time = end_time - start_time;
    }
    global_fullscreen_erase();
}
void time_control_continue(long time_elapsed) {
    long start_time = time(0);
    long end_time = time(0);
    long elapsed_time = end_time - start_time;
    while (elapsed_time < time_elapsed) {
        end_time = time(0);//write_in_str(" ",40,40);
        elapsed_time = end_time - start_time;
    }
}
void write_in_str(string text, int x, int y) {
    HANDLE hout;
    COORD coord;
    coord.X = x;
    coord.Y = y;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout, coord);
    cout << text;
}
void write_in_num(int Number, int x, int y) {
    HANDLE hout;
    COORD coord;
    coord.X = x;
    coord.Y = y;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout, coord);
    cout << Number;
}
void write_in_str(long long int NumberN, int x, int y) {
    HANDLE hout;
    COORD coord;
    coord.X = x;
    coord.Y = y;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout, coord);
    cout << NumberN;
}
void write_in_bool(bool signal, int x, int y) {
    HANDLE hout;
    COORD coord;
    coord.X = x;
    coord.Y = y;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout, coord);
    cout << signal;
}
bool get() {
    //这是一段防止闪过的代码
    //cout<<"fa";
    cin.get();
    cin.get();
    return true;
}
long long int reconvert_bits(string complex_d, int bits) {
    long long int reconvert = 0ll;
    for (unsigned int n = 0; n < complex_d.length(); n++) {
        reconvert = reconvert + base(complex_d.at(n)) * pow(bits, (complex_d.length() - 1 - n));
    }
    return reconvert;

}
int base(char c) {
    char arrc[36] = { '0', '1', '2', '3', '4', '5','6', '7', '8', '9','a', 'b', 'c', 'd', 'e','f','g', 'h', 'i', 'j', 'k','l', 'm', 'n', 'o', 'p','q', 'r','s', 't', 'u', 'v', 'w', 'x','y','z' };
    char arrc2[36] = { 'A', 'B', 'C', 'D', 'E', 'F','H', 'I', 'J', 'K', 'L', 'M','N', 'O', 'P','Q', 'R', 'S', 'R','S','U','V', 'W', 'X', 'Y', 'Z' };
    for (int f = 0; f < 36; f++) {
        if (c == arrc[f]) {
            return f;
        }
        if (c == arrc2[f]) {
            return f + 10;
        }
    }
    return 88;
}
string convertbits(long long int convert, int bits) {
    int s2;
    long long int variable;
    string converted = "";
    while (convert >= 1) {
        variable = convert / bits;
        s2 = convert % bits;
        convert = variable;
        converted = convert_number_to_string(s2) + converted;
    }
    return converted;
}
string convert_number_to_string(int multi_bit) {
    string arr[36] = { "0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
    return arr[multi_bit];
}
long long int pow(int base, int index) {
    long long int value = 1ll;
    if (index == 0) {
        return value;
    }
    for (int j = 0; j < index; j++) {
        value = value * base;
    }
    return value;
}
int error_judge(string complex_d, int previous_bits) {
    int error_info[2] = { 0,0 };
    for (unsigned int k = 0; k < complex_d.length(); k++) {
        if (base(complex_d[k]) == 88) {
            error_info[0] = 1;
            //格式错误，要转化的数字的格式不符合要求
        }
        if (base(complex_d[k]) >= previous_bits) {
            error_info[1] = 2;
        }
        //"要转化的数字中的数字只能小于原本进制数"
    }
    return error_info[0] + error_info[1];
}
