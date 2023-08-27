#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

QImage image(800, 800, QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Rectangle(double x1, double y1, double width, double height)
{
    double x, y, i;
    x = x1;
    y = y1;
    image.setPixel(x1, y1, qRgb(255, 255, 255));
    i = 0;
    while (i < width)
    {
        x += 1;
        image.setPixel(x, y, qRgb(255, 255, 255));
        i++;
    }

    x = x1;
    y = y1;
    image.setPixel(x1, y1, qRgb(255, 255, 255));
    i = 0;
    while (i < height)
    {
        y += 1;
        image.setPixel(x, y, qRgb(255, 255, 255));
        i++;
    }

    x = x1;
    y = y1 + height;
    image.setPixel(x, y, qRgb(255, 255, 255));
    i = 0;
    while (i < width)
    {
        x += 1;
        image.setPixel(x, y, qRgb(255, 255, 255));
        i++;
    }

    x = x1 + width;
    y = y1;
    image.setPixel(x, y, qRgb(255, 255, 255));
    i = 0;
    while (i < height)
    {
        y += 1;
        image.setPixel(x, y, qRgb(255, 255, 255));
        i++;
    }
}

void MainWindow::Rhombus(double x1, double y1, double width, double height)
{
    double x, y, i, dx, dy, step, xi, yi;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    width = ui->textEdit_3->toPlainText().toInt();
    height = ui->textEdit_4->toPlainText().toInt();

    dx = abs(-(width / 2));
    dy = abs(height / 2);
    if (dx >= dy)
        step = dx;
    else
        step = dy;
    dx = (-(width) / 2);
    dy = (height / 2);
    xi = dx / step;
    yi = dy / step;

    x = (2 * x1 + width) / 2;
    y = y1;
    image.setPixel(x, y, qRgb(255, 255, 255));
    i = 0;
    while (i <= step)
    {
        x += xi;
        y += yi;
        image.setPixel(x, y, qRgb(255, 255, 255));
        i++;
    }
    dx = abs(width / 2);
    dy = abs(height / 2);
    if (dx >= dy)
        step = dx;
    else
        step = dy;
    dx = ((width) / 2);
    dy = (height) / 2;
    xi = dx / step;
    yi = dy / step;

    x = (2 * x1 + width) / 2;
    y = y1;
    image.setPixel(x, y, qRgb(255, 255, 255));
    i = 0;
    while (i <= step)
    {
        x += xi;
        y += yi;
        image.setPixel(x, y, qRgb(255, 255, 255));
        i++;
    }

    dx = abs((width) / 2);
    dy = abs(((height) / 2));
    if (dx >= dy)
        step = dx;
    else
        step = dy;
    dx = ((width) / 2);
    dy = (((height) / 2));
    xi = dx / step;
    yi = dy / step;

    x = x1;
    y = (2 * y1 + height) / 2;
    image.setPixel(x, y, qRgb(255, 255, 255));
    i = 0;
    while (i <= step)
    {
        x += xi;
        y += yi;
        image.setPixel(x, y, qRgb(255, 255, 255));
        i++;
    }

    dx = abs((width) / 2);
    dy = abs(((height) / 2));
    if (dx >= dy)
        step = dx;
    else
        step = dy;
    dx = ((width) / 2);
    dy = -((height) / 2);
    xi = dx / step;
    yi = dy / step;

    x = (2 * x1 + width) / 2;
    y = y1 + height;
    image.setPixel(x, y, qRgb(255, 255, 255));
    i = 0;
    while (i <= step)
    {
        x += xi;
        y += yi;
        image.setPixel(x, y, qRgb(255, 255, 255));
        i++;
    }
}

void MainWindow::Circle(double x1, double y1, double width, double height)
{
    double x, y, xc, yc, r, D;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    width = ui->textEdit_3->toPlainText().toInt();
    height = ui->textEdit_4->toPlainText().toInt();

    xc = ((2 * x1 + width) / 2);
    yc = ((2 * y1 + height) / 2);
    r = (width * height) / (2 * sqrt((width * width) + (height * height)));

    x = 0;
    y = r;

    D = 3 - 2 * r;
    while (x <= y)
    {
        image.setPixel(x + xc, y + yc, qRgb(255, 255, 255));
        image.setPixel(y + xc, x + yc, qRgb(255, 255, 255));
        image.setPixel(-y + xc, x + yc, qRgb(255, 255, 255));
        image.setPixel(-x + xc, y + yc, qRgb(255, 255, 255));
        image.setPixel(-x + xc, -y + yc, qRgb(255, 255, 255));
        image.setPixel(-y + xc, -x + yc, qRgb(255, 255, 255));
        image.setPixel(x + xc, -y + yc, qRgb(255, 255, 255));
        image.setPixel(y + xc, -x + yc, qRgb(255, 255, 255));
        if (D < 0)
            D = D + (4 * x) + 6;
        else
        {
            D = D + (4 * (x - y)) + 10;
            y = y - 1;
        }
        x = x + 1;
    }
}

void MainWindow::on_pushButton_clicked()
{
    double x1, y1, width, height;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    width = ui->textEdit_3->toPlainText().toInt();
    height = ui->textEdit_4->toPlainText().toInt();

    Rectangle(x1, y1, width, height);
    Rhombus(x1, y1, width, height);
    Circle(x1, y1, width, height);
    ui->label->setPixmap(QPixmap::fromImage(image));
}




4444444444444444444444444444444444444444444444444444
switch (choice)
        {
        case 1:
            sort(v.begin(), v.end(), Compare);

            vector<Studentinfo>::iterator it = v.begin();

            cout << "\n######################### Sorted Data ##############################" << endl;

            while (it != v.end())
            {
                cout << "\nName of Student            : " << (*it).Name << endl;
                cout << "Roll Number of Student     : " << (*it).Rollno << endl;
                cout << "Date of Birth of Student   : " << (*it).DOB << endl;
                cout << "Mobile Number of Student   : " << (*it).MobileNumber << "\n\n";
                it++;
            }
            break;
        case 2:
            int q;
            cout << "Enter Roll Number for search Operation -----> ";
            cin >> q;

            vector<Studentinfo>::iterator it = v.begin();

            while (it != v.end())
            {
                if ((*it).Rollno == q)
                {
                    break;
                }
                it++;
            }

            if ((*it).Rollno != q)
            {
                cout << "\nStudent with Roll Number '" << q << "' not found in Data!!!" << endl;
            }

            else
            {
                cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
                cout << "\nName of Student            : " << (*it).Name << endl;
                cout << "Roll Number of Student     : " << (*it).Rollno << endl;
                cout << "Date of Birth of Student   : " << (*it).DOB << endl;
                cout << "Mobile Number of Student   : " << (*it).MobileNumber << endl;
                cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
            }
            break;
        case 3:
            string y;
            cout << "Enter Name for search Operation -----> ";
            cin >> y;

            vector<Studentinfo>::iterator it = v.begin();

            while (it != v.end())
            {
                if ((*it).Name == y)
                {
                    break;
                }
                it++;
            }

            if ((*it).Name != y)
            {
                cout << "\nStudent with Name '" << y << "' not found in Data!!!" << endl;
            }

            else
            {
                cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
                cout << "\nName of Student            : " << (*it).Name << endl;
                cout << "Roll Number of Student     : " << (*it).Rollno << endl;
                cout << "Date of Birth of Student   : " << (*it).DOB << endl;
                cout << "Mobile Number of Student   : " << (*it).MobileNumber << endl;
                cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
            }
            break;
        }