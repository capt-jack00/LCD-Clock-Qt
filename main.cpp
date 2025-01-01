#include <QApplication>
#include <QLCDNumber>
#include <QTime>
#include <ctime>
#include <unistd.h>
#include <QObject>
#include <QTimer>
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>

using namespace std;

int localSecond;
int localMinute;
int localHour;

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QMainWindow mainWindow;
    QWidget centralWidget;
    QHBoxLayout layout;

    QLCDNumber secondsClock;
    QLCDNumber minutesClock;
    QLCDNumber hoursClock;

    layout.addWidget(&hoursClock);
    layout.addWidget(&minutesClock);
    layout.addWidget(&secondsClock);

    centralWidget.setLayout(&layout);
    mainWindow.setCentralWidget(&centralWidget);

    QTimer timer;

    QObject::connect(&timer, &QTimer::timeout, [&secondsClock](){
        time_t now = time(nullptr);
        tm* localTime = localtime(&now);
        localSecond = localTime->tm_sec;
        secondsClock.display(localSecond);
    });

    QObject::connect(&timer, &QTimer::timeout, [&minutesClock](){
        time_t now = time(nullptr);
        tm* localTime = localtime(&now);
        localMinute = localTime->tm_min;
        minutesClock.display(localMinute);
    });

    QObject::connect(&timer, &QTimer::timeout, [&hoursClock](){
        time_t now = time(nullptr);
        tm* localTime = localtime(&now);
        localHour = localTime->tm_hour;
        hoursClock.display(localHour);
    });

    timer.start(1000);

    mainWindow.show();
    return app.exec();
}
