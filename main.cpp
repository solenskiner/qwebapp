#include <QtGui/QApplication>
#include <QUrl>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include "mainwindow.hpp"
//#include "session_manager.hpp"

void error() {
    QTextStream out(stdout);
    out << "Usage: qwebapp %u" << '\n';
    out << '\n';
    out << "Just make a desktop shortcut for any page you want," << '\n' << flush;
    out << " passing the url as a parameter. A page manager is comming." << '\n' << flush;
    exit(1);
}

int main(int argc, char *argv[]) {
  QStringList arguments;
  for (int i = 0; i < argc; i++) {
    arguments << QString(argv[i]);
  }

  QUrl url;

  if (arguments.length() == 2) {
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
  }
  /*QApplication a(argc, argv);
  MainWindow w(QUrl("http://www.reddit.com/"));
  w.show();*/
  return a.exec();
}
