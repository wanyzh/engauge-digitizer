#ifndef TEST_SPLINE_H
#define TEST_SPLINE_H

#include <QObject>
#include <QString>
#include "SplinePair.h"
#include <vector>

class SplineAbstract;

/// Unit test of spline library
class TestSpline : public QObject
{
  Q_OBJECT
public:
  /// Single constructor.
  explicit TestSpline(QObject *parent = 0);

signals:

private slots:
  void cleanupTestCase ();
  void initTestCase ();

  void testMultiCoefficientsFromOrdinals ();
  void testMultiSharpTransition ();
  void testMultiSplinesAsControlPoints ();
  void testSingleCoefficientsFromOrdinals ();
  void testSingleSharpTransition ();
  void testSingleSplinesAsControlPoints ();

private:
  bool coefCheckMultiXVersusT (const std::vector<double> &t,
                               const std::vector<SplinePair> &xy,
                               const SplineAbstract &s,
                               double aFinalX,
                               double bFinalX,
                               double cFinalX,
                               double dFinalX) const;
  bool coefCheckMultiYVersusT (const std::vector<double> &t,
                               const std::vector<SplinePair> &xy,
                               const SplineAbstract &s,
                               double aFinalY,
                               double bFinalY,
                               double cFinalY,
                               double dFinalY) const;
  bool coefCheckSingleXVersusT (const std::vector<double> &t,
                                const std::vector<SplinePair> &xy,
                                const SplineAbstract &s,
                                double aFinalY,
                                double bFinalY,
                                double cFinalY,
                                double dFinalY) const;
  bool coefCheckSingleYVersusT (const std::vector<double> &t,
                                const std::vector<SplinePair> &xy,
                                const SplineAbstract &s,
                                double aFinalY,
                                double bFinalY,
                                double cFinalY,
                                double dFinalY) const;
  void coefLoad(std::vector<double> &t,
                std::vector<SplinePair> &xy) const;
  void coefShowInputXVersusT (const SplineAbstract &s,
                              const std::vector<double> &t,
                              const std::vector<SplinePair> &xy) const;
  void coefShowInputYVersusT (const SplineAbstract &s,
                              const std::vector<double> &t,
                              const std::vector<SplinePair> &xy) const;
  void coefShowInputYVersusX (const SplineAbstract &s,
                              const std::vector<SplinePair> &xy) const;
  void coefShowOutput (const QString &leftHandSide,
                       const QString &independentVariable,
                       double tLow,
                       double tHigh,
                       double a,
                       double b,
                       double c,
                       double d) const;
  void testCommonCoefficientsFromOrdinals (bool isSingle,
                                           double aFinalX,
                                           double bFinalX,
                                           double cFinalX,
                                           double dFinalX,
                                           double aFinalY,
                                           double bFinalY,
                                           double cFinalY,
                                           double dFinalY); /// Compare with third party calculations on a web page
  void testCommonSharpTransition (bool isSingle); /// Uses x values in t array to get single-valued function across sharp transition
  void testCommonSplinesAsControlPoints (bool isSingle);
};

#endif // TEST_SPLINE_H
