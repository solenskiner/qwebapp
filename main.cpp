#include <QtGui/QApplication>
#include "mainwindow.hpp"
#include "session_manager.hpp"

void error() {
    QTextStream out(stdout);
    out << "Usage: cute-web-app [%u]" << '\n' << flush;
    exit(1);
}

int main(int argc, char *argv[]) {
  QStringList arguments;
  for (int i = 0; i < argc; i++) {
    arguments << QString(argv[i]);
  }

  QUrl url;

  /*if (arguments.length() == 2) {
    url.setUrl(arguments.at(1));
    if (url.isValid()) {
      QApplication a(argc, argv);
      MainWindow w(url);
      w.show();
      return a.exec();
    }
  }
  else {
    QApplication a(argc, argv);
    session_manager w();
    w.show();
    return a.exec();
  }*/
  QApplication a(argc, argv);
  MainWindow w(QUrl("http://www.facebook.com/"));
  w.show();
  return a.exec();
}
