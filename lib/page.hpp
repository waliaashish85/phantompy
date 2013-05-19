#ifndef PHANTOMPY_PAGE_HPP
#define PHANTOMPY_PAGE_HPP

#include <QtCore>
#include <QtWebKit>
#include <QtWebKitWidgets>
#include <QtNetwork>


class Page: public QObject {
    Q_OBJECT

public:
    Page(QObject *parent=0);
    ~Page();

    void load(const QString &url);
    void setViewSize(int x, int y);

    bool isLoaded();
    bool hasLoadErrors();

    QWebFrame* mainFrame();
    QByteArray cookies();

private:
    bool m_loaded;
    bool m_error;

    QEventLoop m_event_loop;
    QWebPage m_page;
    QSize m_view_size;

private slots:
    void loadFinished(bool ok);
    void replyReceived(QNetworkReply *reply);
};

#endif
