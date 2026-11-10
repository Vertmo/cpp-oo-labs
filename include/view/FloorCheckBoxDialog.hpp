#ifndef FLOOR_CHECKBOX_DIALOG
#define FLOOR_CHECKBOX_DIALOG

#include <QDialog>
#include <QCheckBox>

class FloorCheckBoxDialog : public QDialog {
private:
  std::vector<QCheckBox *> options;

public:
  FloorCheckBoxDialog(int nb);
  std::vector<int> getCheckedNbs() const;
};

#endif
