#pragma once

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QException>

class GreyhoundResource
{
public:
	GreyhoundResource(QUrl url);
	~GreyhoundResource();

	QJsonObject info_query();
	QJsonObject count_query();
	QByteArray read_query();


private:
	QUrl m_base_url;
	QNetworkAccessManager m_qnam;
	QNetworkRequest m_request;
	QNetworkReply *m_reply;
};

class GreyhoundExc : public QException

{

public:
	GreyhoundExc(const QString& msg) : m_msg(msg) {}

	const char* what() const { return m_msg.toStdString().c_str(); }
	const QString& message() const { return m_msg; }

	void raise() const { throw *this; }
	GreyhoundExc *clone() const { return new GreyhoundExc(*this); }
	
private:
	QString m_msg;
};
