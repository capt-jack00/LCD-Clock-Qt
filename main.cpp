#include <QApplication>
#include <QLCDNumber>
#include <QTime>
#include <ctime>
#include <unistd.h>
#include <QObject>
#include <QTimer>

using namespace std;

int localSecond;

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    QLCDNumber clock;
    QTimer timer;

    QObject::connect(&timer, &QTimer::timeout, [&clock](){
        time_t now = time(nullptr);
        tm* localTime = localtime(&now);
        localSecond = localTime->tm_sec;
        clock.display(localSecond);
    });

    timer.start(1000);

    clock.show();
    return app.exec();
}
