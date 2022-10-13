#include "emulationdialog.h"
#include "ui_emulationdialog.h"

EmulationDialog::EmulationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmulationDialog)
{
    ui->setupUi(this);

    setLayout(new QVBoxLayout);

    label_emulationInfo = new QLabel("Вы уверенны, что хотите включить эмуляцию?", this);
    buttonBox = new QDialogButtonBox(this);
    buttonBox->addButton(tr("Начать"), QDialogButtonBox::AcceptRole);
    buttonBox->addButton(tr("Отмена"), QDialogButtonBox::RejectRole);

    layout()->addWidget(label_emulationInfo);
    layout()->addWidget(buttonBox);

    setWindowTitle(tr("Включение эмуляции"));
    adjustSize();

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::hide);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::hide);
}

EmulationDialog::~EmulationDialog()
{
    delete ui;
}
