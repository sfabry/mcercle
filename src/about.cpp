/**
  This file is a part of mcercle
  Copyright (C) 2010-2013 Cyril FRAUSTI

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

#include "about.h"
#include "ui_about.h"
#include "dbase.h"

#include <QDesktopServices>
#include <QUrl>

about::about(database *pdata, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::about)
{
	ui->setupUi(this);

	QImage ico = QImage(":/app/logo_small");
	ui->label_ico->setPixmap(QPixmap::fromImage( ico ));

	QString msg = tr("<b>mcercle</b> version ") + MCERCLE_VERSION; 
	msg += "<br><i>"+ tr("C'est mieux quand c'est simple")+"</i>";
	msg += "<br>"+ tr("Ce programme est un logiciel de gestion pour Auto-entrepreneur/PME.");
	msg +="<br><a href=\"http://frausti.fr\">http://frausti.fr</a>";

	msg += "<br><br>"+ tr("Compilation: ");
	msg +=  __DATE__ ;
	msg += " ";
	msg += __TIME__;
#ifdef _MSC_VER
    msg += "<br>MSVC ";
    msg += QString::number(_MSC_VER);
#else
	msg += "<br>GCC ";
    msg += __VERSION__;
#endif
	msg += "<br><br>" + tr("mcercle utilise :<br>");
	msg += tr("- l&#146;interface graphique Qt4. <a href=\"http://qt-project.org\">http://qt-project.org</a><br>");

	if(pdata->isConnected()){
		if(pdata->getDriverName() == "QSQLITE"){
			QSqlQuery query;
			query.prepare("SELECT sqlite_version();");
			if(query.exec()){
				query.next();
				msg += "- SQLITE v" + query.value(query.record().indexOf("sqlite_version()")).toString()+" <a href=\"http://www.sqlite.org\">http://www.sqlite.org</a><br>";
			}
		}
		else{
			QSqlQuery query;
			query.prepare("SELECT VERSION();");
			if(query.exec()){
				query.next();
				msg += "- MYSQL v" + query.value(query.record().indexOf("VERSION()")).toString()+" <a href=\"http://www.mysql.com/\">http://www.mysql.com/</a><br>";
			}
		}
	}

	// msg += "- FireBird v"+ pdata->getFireBirdVersion() +". <a href=\"http://www.firebirdsql.org\">http://www.firebirdsql.org</a><br>";
   // msg += "- IBPP v"+ database::IBPPversion() +". <a href=\"http://www.ibpp.org\">http://www.ibpp.org</a><br>";
	msg += tr("- Icons Oxygen du bureau kde. <a href=\"http://www.oxygen-icons.org\">http://www.oxygen-icons.org</a>");

	//msg += "<br><br>" + tr("Outils :<br>");
   // msg += "- FlameRobin - <a href=\"http://www.flamerobin.org\">http://www.flamerobin.org</a>";
	msg += "<br><br>"+ tr("Auteur:") + "&#169; 2010-2013";
	msg += "<br>- Cyril Frausti &lt;<a href=\"mailto:cyril.frausti@gmail.com\">cyril.frausti@gmail.com</a>&gt; D&#233;veloppeur";

	msg += "<br><br><p align=\"center\" style=\"font-size:13px;font-weight:bold;color:white;background:#555; \">" + tr("mcercle vous aide dans votre activit\351, aidez son concepteur") + "</p>";

	ui->label_apropos->setText( msg );
	ui->label_apropos->setOpenExternalLinks ( true );
	//Selectionne la tab 0
	ui->tabWidget->setCurrentIndex(0);
}

/*
	http://www.commentcamarche.net/contents/html/htmlcarac.php3
*/
about::~about() {
	delete ui;
}

void about::changeEvent(QEvent *e)
{
	QDialog::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void about::on_pushBut_Close_clicked()
{
	this->close();
}

//don libre https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=72NQ9YWVE8U2W
//don 19.99 https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=75YN3QWER2V9S
void about::on_pushButton_don_clicked()
{
	QDesktopServices::openUrl(QUrl("https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=75YN3QWER2V9S"));
}

void about::on_pushButton_donFree_clicked()
{
	QDesktopServices::openUrl(QUrl("https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=72NQ9YWVE8U2W"));
}
