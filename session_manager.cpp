#include "session_manager.hpp"

#include <QListView>
#include <QList>

session_manager::session_manager() {
  layout = new QGridLayout(this);
  setLayout(layout);
}
