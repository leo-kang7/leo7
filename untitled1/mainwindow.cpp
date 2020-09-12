#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include<iostream>
#include<string>
using namespace std;
#include<stack>
#include<vector>
#include<cstdlib>
#include<limits.h>
bool isNum(char ch);
bool isOperate(char ch);
int level(char ch);
double scd(string s);
double getValue(vector<string> V);
vector<string> midToPost(string s);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     system_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::system_init(){

    //进制转换
    input.addButton(ui->radioButton1,2);
    input.addButton(ui->radioButton2,10);
    input.addButton(ui->radioButton3,16);
    ui->radioButton2->setChecked(true);

    output.addButton(ui->radioButton4,2);
    output.addButton(ui->radioButton5,10);
    output.addButton(ui->radioButton6,16);
    output.setId(ui->radioButton5,10);
    ui->radioButton5->setChecked(true);
    connect(ui->num0,&QPushButton::clicked,this,&MainWindow::num0Clicked);
    connect(ui->num1,&QPushButton::clicked,this,&MainWindow::num1Clicked);
    connect(ui->num2,&QPushButton::clicked,this,&MainWindow::num2Clicked);
    connect(ui->num3,&QPushButton::clicked,this,&MainWindow::num3Clicked);
    connect(ui->num4,&QPushButton::clicked,this,&MainWindow::num4Clicked);
    connect(ui->num5,&QPushButton::clicked,this,&MainWindow::num5Clicked);
    connect(ui->num6,&QPushButton::clicked,this,&MainWindow::num6Clicked);
    connect(ui->num7,&QPushButton::clicked,this,&MainWindow::num7Clicked);
    connect(ui->num8,&QPushButton::clicked,this,&MainWindow::num8Clicked);
    connect(ui->num9,&QPushButton::clicked,this,&MainWindow::num9Clicked);
    connect(ui->fu,&QPushButton::clicked,this,&MainWindow::fuClicked);
    connect(ui->plus,&QPushButton::clicked,this,&MainWindow::plusClicked);
    connect(ui->min,&QPushButton::clicked,this,&MainWindow::minClicked);
    connect(ui->mul,&QPushButton::clicked,this,&MainWindow::mulClicked);
    connect(ui->div,&QPushButton::clicked,this,&MainWindow::divClicked);
    connect(ui->equal,&QPushButton::clicked,this,&MainWindow::equalClicked);
    connect(ui->dot,&QPushButton::clicked,this,&MainWindow::dotClicked);
    connect(ui->clear,&QPushButton::clicked,this,&MainWindow::clearClicked);
    connect(ui->delete_2,&QPushButton::clicked,this,&MainWindow::deleteClicked);
    connect(ui->left,&QPushButton::clicked,this,&MainWindow::leftClicked);
    connect(ui->right,&QPushButton::clicked,this,&MainWindow::rightClicked);
    connect(ui->sin,&QPushButton::clicked,this,&MainWindow::sinClicked);
    connect(ui->cos,&QPushButton::clicked,this,&MainWindow::cosClicked);
    connect(ui->log,&QPushButton::clicked,this,&MainWindow::logClicked);
}
void MainWindow::code_change(){
    QString ss=ui->lineEdit_input->text();
    qDebug()<<"sss"<<input.checkedId();
    on_lineEdit_input_textChanged(ss);
}
void MainWindow::on_lineEdit_input_textChanged(const QString &arg1)//将输入的字符串转换成相应进制的数
{
    bool ok;
    qDebug()<<arg1;
    code_input=input.checkedId();
    code_resu=output.checkedId();
    switch (code_input) {
    case 2:
        start=arg1.toInt(&ok,2);
        break;
    case 8:
        start=arg1.toInt(&ok,8);
        break;
    case 10:
        start=arg1.toInt(&ok,10);
        break;
    case 16:
        start=arg1.toInt(&ok,16);
        break;
    }
    print_resu();
}
//进制转换输出
void MainWindow::print_resu(){
    switch (code_resu) {
    case 2:
        resu=QString::number(start,2);
        break;
    case 8:
        resu=QString::number(start,8);
        break;
    case 10:
       resu=QString::number(start,10);
        break;
    case 16:
        resu=QString::number(start,16);
        break;
    }
    ui->lineEdit_output->setText(resu);
}

void MainWindow::num0Clicked()  //以下是实现相应的槽函数
{
    input2='0';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num1Clicked()
{
    input2='1';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num2Clicked()
{
    input2='2';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num3Clicked()
{
    input2='3';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num4Clicked()
{
    input2='4';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num5Clicked()
{
    input2='5';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num6Clicked()
{
    input2='6';
   ui->edit_show->insertPlainText(input2);
}

void MainWindow::num7Clicked()
{
    input2='7';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num8Clicked()
{
    input2='8';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::num9Clicked()
{
    input2='9';
    ui->edit_show->insertPlainText(input2);
}
void MainWindow::plusClicked()
{
    input2='+';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::minClicked()
{
    input2='-';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::mulClicked()
{
    input2='*';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::divClicked()
{
    input2='/';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::dotClicked() //小数点
{
    input2='.';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::fuClicked() //正负号
{
        input2='-';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::leftClicked()//左括号
{
    input2='(';
    ui->edit_show->insertPlainText(input2);
}

void MainWindow::rightClicked()//右括号
{
    input2=')';
    ui->edit_show->insertPlainText(input2);
}
void MainWindow::deleteClicked()
{   QString input2=ui->edit_show->toPlainText();
    input2 = input2.left(input2.length()-1); //减去一字符
    ui->edit_show->clear();
    ui->edit_show->insertPlainText(input2);
}
void MainWindow::clearClicked() //直接清空
{
    ui->edit_show->clear();
}
void MainWindow::sinClicked(){

}
void MainWindow::cosClicked(){

}
void MainWindow::logClicked(){

}



bool isNum(char ch) {
    if(ch >= '0' && ch <= '9') return true;
    else return false;
}

bool isOperate(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
    return true;
    else return false;
}

int level(char ch) {
    switch(ch) {
        case '(' :
            return 5;
        case '*' :
            return 4;
        case '/' :
            return 4;
        case '+' :
            return 3;
        case '-' :
            return 3;
        case ')':
            return 2;
    }
}
/*字符串转数字*/
double scd(string s) {
    if(s.length() == 0) return INT_MAX;

    bool flag = false;
    for(int i = 0; i < s.length(); i++) {
        if(i == 0 && s[i] == '-') continue;
        else if(s[i] == '.' && !flag) {
            if(i > 0 && isNum(s[i-1])) {
                flag = true;
                continue;
            }
            else return INT_MAX;
        }
        else if(isNum(s[i])) continue;
        else return INT_MAX;
    }

    double result = atof(s.c_str());
    return result;
}

 /*由中缀表达式得到后缀表达式, 向量V存储结果*/
vector<string> midToPost(string s) {
    stack<char> S; /*符号栈*/
    vector<string> V; /*后缀表达式*/
    int i = 0;
    while(i < s.length()) {
        if(isNum(s[i])) {
            string str = "";
            while(isNum(s[i]) || s[i] == '.') {
                str += s[i];
                i++;
            }
            V.push_back(str);
        }

        else if(isOperate(s[i])){
            /*负数情况*/
            if(s[i] == '-' && (i == 0 || !isNum(s[i-1]))) {
                string str = "-"; i++;
                while(isNum(s[i]) || s[i] == '.') {
                    str += s[i]; i++;
                }
                V.push_back(str);
            }else{
                if(S.empty()){
                    S.push(s[i]); i++;
                }else {
                    int initial = level(s[i]);
                    if(initial == 2) {
                        while(level(S.top()) != 5 && !s.empty()) {
                            string str = "";
                            str += S.top();
                            V.push_back(str);
                            S.pop();
                        }
                        if(S.top() == '(') S.pop(); i++;
                    } else {
                        while(!S.empty() && initial <= level(S.top()) && level(S.top()) != 5) {
                            string str = "";
                            str += S.top();
                            V.push_back(str);
                            S.pop();
                        }
                        S.push(s[i]); i++;
                    }
                }
            }
        }
        else{
            cout << "表达式出错" << endl;
            V.clear();
            return V;
        }
    }
    while(!S.empty()) {
        string str = ""; str += S.top();
        S.pop();
        V.push_back(str);
    }
    //for(int i = 0; i < V.size(); i++) cout << V[i] << "[]";
    return V;
}

/*后缀表达式得到最终结果*/
double getValue(vector<string> V) {
    stack<double> S;
    for(int i = 0; i < V.size(); i++) {
    /*操作运算符*/
        if(V[i].length() == 1 && isOperate(V[i][0])) {
            double a = 0, b = 0;
            if(!S.empty()) {
                a = S.top(); S.pop();
            }else return INT_MAX;

            if(!S.empty()) {
                b = S.top(); S.pop();
            }else return INT_MAX;

            switch(V[i][0]) {
                case '+':
                    S.push(b+a);
                    break;
                case '-':
                    S.push(b-a);
                    break;
                case '*':
                    S.push(b*a);
                    break;
                case '/':
                    S.push(b/a);
                    break;
                default:
                    return INT_MAX;
            }
        }else {
            if(scd(V[i]) == INT_MAX) return INT_MAX;
            else S.push(scd(V[i]));
        }
    }
    if(S.empty()) return INT_MAX;

    double value = S.top();
    S.pop();
    return value;
}
void MainWindow::equalClicked(){
    QString input3=ui->edit_show->toPlainText();
    string inputTemp =input3.toStdString();
    vector<string> expression = midToPost(inputTemp);
    double value = getValue(expression);
    input3=' ';
    if(value != INT_MAX) {
      input3=input3+"="+QString::number(value);
    ui->edit_show->insertPlainText(input3);
    }else{
      input3=input3+"=syntax error";
     ui->edit_show->insertPlainText(input3);
    }
}
