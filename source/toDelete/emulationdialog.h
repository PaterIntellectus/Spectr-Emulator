#ifndef EMULATIONDIALOG_H
#define EMULATIONDIALOG_H

#include <QDialog>

#include <QDialogButtonBox>
#include <QPushButton>
#include <QLabel>

#include <QVBoxLayout>

namespace Ui {
class EmulationDialog;
}

class EmulationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmulationDialog(QWidget *parent = nullptr);
    ~EmulationDialog();

private:
    Ui::EmulationDialog *ui;

    QLabel *label_emulationInfo{ nullptr };
    QDialogButtonBox *buttonBox{ nullptr };
};

#endif // EMULATIONDIALOG_H
