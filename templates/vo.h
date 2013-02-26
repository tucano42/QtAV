
#ifndef QTAV_%CLASS:u%_H
#define QTAV_%CLASS:u%_H

#include <QtAV/VideoRenderer.h>
#include <QWidget>

namespace QtAV {

class %CLASS%Private;
class Q_EXPORT %CLASS% : public QWidget, public VideoRenderer
{
    Q_OBJECT
    DPTR_DECLARE_PRIVATE(%CLASS%)
public:
    %CLASS%(QWidget* parent = 0, Qt::WindowFlags f = 0);
    virtual ~%CLASS%();

    /* WA_PaintOnScreen: To render outside of Qt's paint system, e.g. If you require
     * native painting primitives, you need to reimplement QWidget::paintEngine() to
     * return 0 and set this flag
     * If paintEngine != 0, the window will flicker when drawing without QPainter.
     * Make sure that paintEngine returns 0 to avoid flicking.
     */
    virtual QPaintEngine* paintEngine() const;
    /*http://lists.trolltech.com/qt4-preview-feedback/2005-04/thread00609-0.html
     * true: paintEngine is QPainter. Painting with QPainter support double buffer
     * false: no double buffer, should reimplement paintEngine() to return 0 to avoid flicker
     */
    //TODO: move to base class
	bool useQPainter() const;
	void useQPainter(bool qp);
protected:
    virtual void convertData(const QByteArray &data);
    virtual void paintEvent(QPaintEvent *);
    virtual void resizeEvent(QResizeEvent *);
    //stay on top will change parent, hide then show(windows). we need GetDC() again
    virtual void showEvent(QShowEvent *);
    virtual bool write();
};

} //namespace QtAV

#endif // QTAV_%CLASS%_H
