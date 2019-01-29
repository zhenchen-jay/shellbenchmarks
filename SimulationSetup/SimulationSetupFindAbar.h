#ifndef SIMULATIONSETUPFINDABAR_H
#define SIMULATIONSETUPFINDABAR_H

#include "SimulationSetup.h"
#include "../alglib/stdafx.h"
#include "../alglib/optimization.h"

struct SimulationSetupFindAbar : public SimulationSetup
{
    public:
    virtual void buildRestFundamentalForms(const SecondFundamentalFormDiscretization &sff) override;
    void findFirstFundamentalForms(const SecondFundamentalFormDiscretization &sff);
    void getFunctionGradient(const alglib::real_1d_array &x, double &f, alglib::real_1d_array &df);
    
    void testFucntionGradient(const SecondFundamentalFormDiscretization &sff);
    
    private:
    void computeInvMatDeriv(Eigen::Matrix2d A, Eigen::Matrix<double, 4, 3> &dA); // Compute the derivative of A*A^T
    void computeSqrtDetDerv(Eigen::Matrix2d A, Eigen::Vector3d &diffSqrtDet); // // Compute the derivative of A*A^T
    
    bool loadAbars();   // The path is given by abarPath + "L_list.dat".  abar = L*L^T
    void saveAbars();

    private:
    std::vector<Eigen::Matrix<double, 4, 9> > aderivs;
    std::vector<Eigen::MatrixXd > bderivs;
    std::vector<Eigen::Matrix2d> atargets;            // The first fundamental form of the target shape
    std::vector<Eigen::Matrix2d> btargets;            // The first fundamental form of the target shape
    double lameAlpha;
    double lameBeta;

};



#endif
