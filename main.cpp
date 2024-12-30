#include <QApplication>
#include <QLCDNumber>
#include <QTime>
#include <ctime>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    QLCDNumber clock;

    time_t now = time(nullptr);
    tm* localTime = localtime(&now);

    int localSecond = localTime->tm_sec;
    QTime time (14, 0, localSecond, 0);
    sleep(1);

    clock.display(time.second());
    clock.show();
    return app.exec();
}
