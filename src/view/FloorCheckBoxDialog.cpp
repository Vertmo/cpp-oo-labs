#include <QCheckBox>
#include <QVBoxLayout>
#include <QString>
#include <QPushButton>

#include "view/FloorCheckBoxDialog.hpp"

FloorCheckBoxDialog::FloorCheckBoxDialog(int nb) : QDialog() {
  QVBoxLayout *layout = new QVBoxLayout(this);

  for (int i = 0; i < nb; i++) {
    QString s;
    s.setNum(i);
    QCheckBox *box = new QCheckBox(s, this);
    layout->addWidget(box);
    options.push_back(box);
  }

  QPushButton *okButton = new QPushButton("Ok", this);
  layout->addWidget(okButton);
  connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
}

std::vector<int> FloorCheckBoxDialog::getCheckedNbs() const {
  std::vector<int> vec;
  for (size_t i = 0; i < options.size(); i++) {
      if(options[i]->isChecked()) vec.push_back(i);
  }
  return vec;
}
