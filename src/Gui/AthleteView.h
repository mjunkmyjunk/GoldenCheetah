#include "ChartSpace.h"
#include "OverviewItems.h"

class AthleteView : public ChartSpace
{
    Q_OBJECT

public:
    AthleteView(Context *context);

public slots:
    void configChanged(qint32);

};

// the athlete display
class AthleteCard : public ChartSpaceItem
{
    Q_OBJECT

    public:

        AthleteCard(ChartSpace *parent, QString path);

        void itemPaint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        void itemGeometryChanged() {}
        void setData(RideItem *) {}
        void setDateRange(DateRange) {}
        QWidget *config() { return new OverviewItemConfig(this); }

        // create and config
        static ChartSpaceItem *create(ChartSpace *parent) { return new AthleteCard(parent, ""); }

    public slots:
        void opening(QString, Context*);
        void closing(QString, Context*);
        void loadProgress(QString, double);

    private:
        double loadprogress;
        Context *context;
        QString path;
        QImage avatar;
};

