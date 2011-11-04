#ifndef SESSION_MANAGER_HPP
#define SESSION_MANAGER_HPP

#include <QWidget>
#include <QGridLayout>

class session_manager : public QWidget {
  Q_OBJECT
  public:
     session_manager();
  signals:
  public slots:
  private:
      QGridLayout* layout;
};

#endif // SESSION_MANAGER_HPP
