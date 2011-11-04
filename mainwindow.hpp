#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QGridLayout>
#include <QtWebKit>
#include <QWebSettings>

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QUrl site);
    ~MainWindow();
  signals:
  public slots:
    void handle_link(const QUrl& url);
    void handle_redirect(const QUrl& url);
    void handle_loaded(bool loaded);
  private:
    void set_data_paths(QWebView* view);
  //data:
    QUrl* site;
    QWebView* view[2];
    QWebSettings* settings;
  //
};

#endif // MAINWINDOW_HPP
