#include <MainWindow.hpp>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow win;
    win.show();

    return app.exec();
}
