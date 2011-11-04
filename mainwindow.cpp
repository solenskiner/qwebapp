#include "mainwindow.hpp"
#include <QAction>
 #include <QDesktopServices>

/*
some class to store... umm.. current web-app data:
favicon, domain, name, cache, form data, cookies, passwords, html5 and database etc etc
which is a view of the filesystem data for it
ability to enumerate instantiations (on disk)
model for QListView
or something like that

QSettings cfg(QSettings::IniFormat, QSettings::UserScope, "organization", "application");
QString config_dir = QFileInfo(cfg.fileName()).absolutePath() + "/";
might be interesting
*/

#define VIEW_MAIN    0
#define VIEW_HIDDEN 1

MainWindow::MainWindow(QUrl url) {
  site = new QUrl(url);
  for (int i = 0; i < 2; i++) {
    view [i]= new QWebView(this);
    set_data_paths(view[i]);
  }
  setCentralWidget(view[0]);

  view[VIEW_MAIN]->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
  connect(view[VIEW_MAIN], SIGNAL(linkClicked(const QUrl&)), this, SLOT(handle_link(const QUrl&)));
  connect(view[VIEW_HIDDEN], SIGNAL(urlChanged(const QUrl&)), this, SLOT(handle_redirect(const QUrl&)));
  connect(view[VIEW_HIDDEN], SIGNAL(loadFinished(bool)), this, SLOT(handle_loaded(bool)));

  view[VIEW_MAIN]->load(url);
  view[VIEW_MAIN]->show();
}

void MainWindow::handle_redirect(const QUrl &url) {
  if (site->host() != url.host()) {
    view[VIEW_HIDDEN]->stop();
    QDesktopServices::openUrl(url);
  }
}

void MainWindow::handle_link(const QUrl &url) {
  if (site->host() == url.host())
    view[VIEW_MAIN]->load(url);
  else
    QDesktopServices::openUrl(url);
  //
}
void MainWindow::handle_loaded(bool loaded) {
  view[VIEW_MAIN]->setPage(view[VIEW_HIDDEN]->page());
}

void MainWindow::set_data_paths(QWebView* view) {
  view->settings()->setIconDatabasePath(QDesktopServices::DataLocation + QDir::separator() +
                                                                              QCoreApplication::applicationName() + QDir::separator() +
                                                                              site->toString() + QDir::separator() +
                                                                              "IconDatabase"
                                                                              );
  view->settings()->setLocalStoragePath(QDesktopServices::DataLocation + QDir::separator() +
                                                                              QCoreApplication::applicationName() + QDir::separator() +
                                                                              site->toString() + QDir::separator() +
                                                                              "LocalStorage"
                                                                              );
  view->settings()->setOfflineStoragePath(QDesktopServices::DataLocation + QDir::separator() +
                                                                              QCoreApplication::applicationName() + QDir::separator() +
                                                                              site->toString() + QDir::separator() +
                                                                              "OfflineStorage"
                                                                              );
  view->settings()->setOfflineWebApplicationCachePath(QDesktopServices::DataLocation + QDir::separator() +
                                                                                                          QCoreApplication::applicationName() + QDir::separator() +
                                                                                                          site->toString() + QDir::separator() +
                                                                                                          "OfflineWebApplicationCache"
                                                                                                          );
}

MainWindow::~MainWindow() {
  disconnect(view[VIEW_MAIN], SIGNAL(linkClicked(const QUrl&)), this, SLOT(handle_link(const QUrl&)));
  disconnect(view[VIEW_HIDDEN], SIGNAL(urlChanged(const QUrl&)), this, SLOT(handle_redirect(const QUrl&)));
  disconnect(view[VIEW_HIDDEN], SIGNAL(loadFinished(bool)), this, SLOT(handle_loaded(bool)));
  delete site;
  delete view[VIEW_MAIN];
  delete view[VIEW_HIDDEN];
}
