// BlackScholes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "qrecorder.h"
#include "intrin.h"
#include <cmath>
using namespace vstech;

template<typename mdouble>
mdouble BlackScholes(
	mdouble S0, mdouble K, mdouble r, mdouble vol, mdouble T, mdouble unused) {
	return S0 * std::normal_cdf((std::log(S0 / K) + T * (r + 0.5 * (std::pow(vol, 2)))) /
		(vol * std::sqrt(T))) - std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
			T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T)));
}

template<typename mdouble>
mdouble BlackScholes1(
    const mdouble& S0, const mdouble& K, const mdouble& r, const mdouble& vol, const mdouble& T) {

    return std::erfc(S0); /*  - std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
            T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T))) */;

//    return std::log(S0) + std::pow(vol, 2);
//    return S0*S0 + std::pow(vol, 2);
}

template<typename mdouble>
mdouble BlackScholes2(
    const mdouble& S0, const mdouble& K, const mdouble& r, const mdouble& vol, const mdouble& T) {

    return std::exp(S0); /*  - std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
            T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T))) */;

            //    return std::log(S0) + std::pow(vol, 2);
            //    return S0*S0 + std::pow(vol, 2);
}

template<typename mdouble>
mdouble BlackScholes3(
    const mdouble& S0, const mdouble& K, const mdouble& r, const mdouble& vol, const mdouble& T) {

    return std::log(S0); /*  - std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
            T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T))) */;

            //    return std::log(S0) + std::pow(vol, 2);
            //    return S0*S0 + std::pow(vol, 2);
}

template<typename mdouble>
mdouble BlackScholes4(
    const mdouble& S0, const mdouble& K, const mdouble& r, const mdouble& vol, const mdouble& T) {

    return std::pow(S0,3); /*  - std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
            T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T))) */;

            //    return std::log(S0) + std::pow(vol, 2);
            //    return S0*S0 + std::pow(vol, 2);
}

template<typename mdouble>
mdouble BlackScholes5(
    const mdouble& S0, const mdouble& K, const mdouble& r, const mdouble& vol, const mdouble& T) {
    return S0 * std::normal_cdf((std::log(S0 / K) + T * (r + 0.5 * (std::pow(vol, 2)))) /
        (vol * std::sqrt(T))) - std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
            T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T)));
}

template<typename mdouble>
mdouble BlackScholes6(
    const mdouble& S0, const mdouble& K, const mdouble& r, const mdouble& vol, const mdouble& T) {
    return /*S0 * std::normal_cdf((std::log(S0 / K) + T * (r + 0.5 * (std::pow(vol, 2)))) /
        (vol * std::sqrt(T))) - */std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
            T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T)));
}

#define _USE_MATH_DEFINES
#include "math.h"


namespace std
{
    double normal_cdf(const double& x)
    {
        return std::erfc(-x * M_SQRT1_2) * 0.5;
    }

    double normal_pdf(const double& x)
    {
        return 1.0/sqrt(2*M_PI)*std::exp(-0.5*x*x);
    }

}

template<typename mdouble>
mdouble BlackScholes8(
    const mdouble& S0, const mdouble& K, const mdouble& r, const mdouble& vol, const mdouble& T) {
    return S0 * std::normal_cdf((std::log(S0 / K) + T * (r + 0.5 * (std::pow(vol, 2)))) /
        (vol * std::sqrt(T))) - std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
            T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T)));
}


template<typename mdouble>
mdouble BlackScholes(
    const mdouble& S0, const mdouble& K, const mdouble& r, const mdouble& vol, const mdouble& T) {

    return BlackScholes8(S0, K, r, vol, T);

}

double BlackScholes_closedform(const double& S0, const double& K, const double& r, const double& vol, const double& T, double& dBSdS0, double& dBSdK, double& dBSdr, double& dBSdvol,
    double& d2BSdS02, double& d2BSdKdS0, double& d2BSdrdS0, double& d2BSdvoldS0, double& d3BSdS03)
{
    double BS = BlackScholes(S0, K, r, vol, T);

    double d1 = (std::log(S0 / K) + T * (r + 0.5 * vol * vol)) / vol / std::sqrt(T);
    double d2 = d1 - vol * std::sqrt(T);

    d2BSdS02 = std::normal_pdf(d1)/S0/vol/std::sqrt(T);
    d2BSdKdS0 = -d2BSdS02 * S0 / K;
    d2BSdrdS0 = d2BSdS02 * S0 * T;
    d2BSdvoldS0 = d2BSdS02*S0*vol*std::sqrt(T)*(std::sqrt(T)-d1/vol);
    dBSdS0 = std::normal_cdf(d1);
    dBSdK = (std::normal_pdf(d2) / vol / std::sqrt(T) - std::normal_cdf(d2)) * std::exp(-r * T) - S0 * S0 / K * d2BSdS02;
    dBSdr = K * T * exp(-r * T) * std::normal_cdf(d2);
    dBSdvol = S0*std::sqrt(T)*std::normal_pdf(d1);
    d3BSdS03 = -d1*d2BSdS02/S0/vol/std::sqrt(T)- d2BSdS02/S0;

    return BS;
}


#include  <iostream>

void simple_example()
{
    qrecorder<__m256d> rec;

    qdouble x(1.2);

    rec.start();

    rec.input(x);

    qdouble y = x * x * x;

    rec.output(y);

    rec.stop();

    auto g = rec.graph();

    auto ws = g.workspace();

    //    ws.set_value(S0, 120);

    g.run(ws);

    auto value = ws.get_value(y);

    std::cout << *(double*)&value << std::endl;

    auto dg = g.forwardAD();

    auto wsd = dg.workspace();

    wsd.set_dual(x, 1.0);

    dg.run(wsd);

    auto res0 = wsd.get_value(y);
    auto res1 = wsd.get_dual(y);

    std::cout << *(double*)&res0 << std::endl;
    std::cout << *(double*)&res1 << std::endl;

    auto dg2 = dg.forwardAD();

    auto ws2 = dg2.workspace();

    ws2.set_dual(x, 1.0);
    ws2.set_dual(x, 1.0, 2);

    dg2.run(ws2);

    auto d0 = ws2.get_value(y);
    auto d1 = ws2.get_dual(y);
    auto d2 = ws2.get_dual(y, 2);

    std::cout << *(double*)&d0 << std::endl;
    std::cout << *(double*)&d1 << std::endl;
    std::cout << *(double*)&d2 << std::endl;

}

#include <chrono>
#include <vector>
double round_error(const double& err)
{
    return (abs(err) < 1.5e-9 ? 0.0 : err);
}

void simple_example2()
{
    qrecorder<__m256d> rec;

    qdouble x;

    rec.start();

    double xv = 0.1;
    double dxv = 0.0000001;

    x = xv;

    rec.input(x);

    qdouble y = std::erfc(x);

    rec.output(y);

    rec.stop();

    auto g = rec.graph();

    auto rec_start = std::chrono::high_resolution_clock::now();

    uint64_t n = 5;

    std::vector<double> fd_res;
    std::vector<double> fd2_res;

    for (uint64_t i = 0; i < n; ++i)
    {
        // Bump and recalc to get numerical value

        auto ws = g.workspace();
        if (i > 0)
            for (uint64_t j = 0; j < i; ++j)
                ws.set_dual(x, 1.0, j + 1);
        g.run(ws);
        auto base_val = i == 0 ? ws.get_value(y) : ws.get_dual(y, i);
        ws.set_value(x, xv + dxv);
        g.run(ws);
        auto bumped_up = i == 0 ? ws.get_value(y) : ws.get_dual(y, i);
        ws.set_value(x, xv - dxv);
        g.run(ws);
        auto bumped_dn = i == 0 ? ws.get_value(y) : ws.get_dual(y, i);
        auto fd = _mm256_div_pd(_mm256_sub_pd(bumped_up, bumped_dn),_mm256_set1_pd(2.0*dxv));
        auto fd2 = _mm256_div_pd(_mm256_sub_pd(_mm256_add_pd(bumped_up, bumped_dn), _mm256_add_pd(base_val, base_val)), _mm256_set1_pd(dxv * dxv));
        fd_res.push_back(*(double*)&fd);
        fd2_res.push_back(*(double*)&fd2);
        g = g.forwardAD();
        if (i % 10 == 0)
            std::cout << "Done with " << i << std::endl;

    }

    auto rec_end = std::chrono::high_resolution_clock::now();

    auto rec_duration = std::chrono::duration_cast<std::chrono::microseconds>(rec_end - rec_start);

    auto ws = g.workspace();

    for (uint64_t i = 0; i < n; ++i)
        ws.set_dual(x, 1.0, i + 1);

    auto calc_start = std::chrono::high_resolution_clock::now();

    g.run(ws);

    auto calc_end = std::chrono::high_resolution_clock::now();

    auto calc_duration = std::chrono::duration_cast<std::chrono::microseconds>(calc_end - calc_start);

    for (uint64_t i = 0; i <= n; ++i) {

        auto res = i > 0 ? ws.get_dual(y, i) : ws.get_value(y);
        double res_calc = *(double*)&res;
        double res_actual = i == 0 ? std::erfc(xv) : fd_res[i - 1];
        std::cout << i << ") calc=" << res_calc << " actual=" << res_actual;
        if (i > 1)
            std::cout << " alternate=" << fd2_res[i - 2];
        std::cout << " error=" << round_error(res_calc - res_actual);
        if (i > 1)
            std::cout << " alt_error=" << round_error((res_calc - fd2_res[i - 2])/res_calc);
        std::cout << std::endl;
    }

#ifndef main
    std::cout << "Calc Time=" << calc_duration.count() << std::endl;
    std::cout << "Rec Time=" << rec_duration.count() << std::endl;
#endif
}

void simple_example3()
{
    qrecorder<__m256d> rec;

    rec.start();

    qdouble x(0), y(1), z, f;

    rec.input(x);
    rec.input(y);

    double cst = 1.0 / std::sqrt(2.0);

    for (int i = 0; i <= 2*0 + 50 * 0 + 1 * 100; i++) {
        for (int j = 1; j < 2*0 + 50 * 0 + 1 * 100; j++) {
            z = std::exp(std::log(x * y) * cst);
            y = std::exp(std::log(x / y) * cst);
            x = z;
        }
    }
    f = x;
    rec.output(f);

    rec.stop();

    auto g = rec.graph();

    auto ws = g.workspace();

    double x_init(3), y_init(2);

    ws.set_value(x, x_init);
    ws.set_value(y, y_init);

    auto calc_start = std::chrono::high_resolution_clock::now();

    g.run(ws);

    auto res = ws.get_value(f);

    std::cout << *(double*)&res << std::endl;

    auto g1 = g.forwardAD();

    auto ws1 = g1.workspace();

    ws1.set_value(x, x_init);
    ws1.set_value(y, y_init);

    ws1.set_dual(x, 1.0);
    ws1.set_dual(y, 0.0);

    g1.run(ws1);

    auto dx = ws1.get_dual(f);

    ws1.set_dual(x, 0.0);
    ws1.set_dual(y, 1.0);

    g1.run(ws1);

    auto dy = ws1.get_dual(f);

    std::cout << *(double*)&dx << std::endl;
    std::cout << *(double*)&dy << std::endl;

    auto g2 = g1.forwardAD();

    auto ws2 = g2.workspace();

    ws2.set_value(x, x_init);
    ws2.set_value(y, y_init);
    ws2.set_dual(x, 1.0);
    ws2.set_dual(y, 0.0);
    ws2.set_dual(x, 1.0, 2);
    ws2.set_dual(y, 0.0, 2);

    g2.run(ws2);

    auto d2fdx2 = ws2.get_dual(f,2);

    double d2fdx2_calc = *(double*)&d2fdx2;

    ws2.set_dual(x, 0.0, 2);
    ws2.set_dual(y, 1.0, 2);
    g2.run(ws2);
    auto d2fdxdy = ws2.get_dual(f, 2);


    // Let us get the same result via bump and reprice

    ws1.set_dual(x, 1.0);
    ws1.set_dual(y, 0.0);

    double bump_x = 0.0001;

    ws1.set_value(x, x_init + bump_x);
    g1.run(ws1);
    auto dfdx_up = ws1.get_dual(f);

    ws1.set_value(x, x_init - bump_x);
    g1.run(ws1);
    auto dfdx_dn = ws1.get_dual(f);

    auto d2fdx2_bump = _mm256_sub_pd(dfdx_up, dfdx_dn);
    d2fdx2_bump = _mm256_div_pd(d2fdx2_bump,_mm256_set1_pd(2*bump_x));

    double d2fdx2_fd = *(double*)&d2fdx2_bump;

    std::cout << "d2f/dx^2=" << d2fdx2_calc << " d2f/dx^2 fd=" << d2fdx2_fd << " error=" << round_error(d2fdx2_fd- d2fdx2_calc) << std::endl;

    // Let us try backward

    auto dg1b = g.backwardAD();

    auto ws1b = dg1b.workspace();

    ws1b.set_value(x, x_init);
    ws1b.set_value(y, y_init);

    ws1b.set_adjoint(f,1.0);

    dg1b.run(ws1b);

    auto resb = ws1b.get_value(f);
    auto dxb = ws1b.get_adjoint(x);
    auto dyb = ws1b.get_adjoint(y);

    auto dfdx_fwd = *(double*)&dx;
    auto dfdx_bkwd = *(double*)&dxb;

    auto dfdy_fwd = *(double*)&dy;
    auto dfdy_bkwd = *(double*)&dyb;

    std::cout << "Forward df/dx=" << dfdx_fwd << " Backward df/dx=" << dfdx_bkwd << " error=" << round_error(dfdx_fwd - dfdx_bkwd) << std::endl;
    std::cout << "Forward df/dy=" << dfdy_fwd << " Backward df/dy=" << dfdy_bkwd << " error=" << round_error(dfdy_fwd - dfdy_bkwd) << std::endl;

    // Let us try backward forward

    auto dg2 = dg1b.forwardAD();

    auto ws2b = dg2.workspace();

    ws2b.set_value(x, x_init);
    ws2b.set_value(y, y_init);
    ws2b.set_adjoint(f, 1.0);
    ws2b.set_dual(x, 1.0, 2);

    dg2.run(ws2b);

    auto resbf = ws2b.get_value(f);
    auto dxbw = ws2b.get_adjoint(x);
    auto dybw = ws2b.get_adjoint(y);
    auto dx2 = ws2b.get_dual(x, 2);
    auto dxdy = ws2b.get_dual(y, 2);

    auto d2fdx2_bkwdfwd = *(double*)&dx2;
    auto d2fdxdy_fwdfwd = *(double*)&d2fdxdy;
    auto d2fdxdy_bkwdfwd = *(double*)&dxdy;

    std::cout << "d2f/dx^2=" << d2fdx2_bkwdfwd << " d2f/dx^2=" << d2fdx2_fd << " error=" << round_error(d2fdx2_fd - d2fdx2_bkwdfwd) << std::endl;
    std::cout << "d2f/dx dy=" << d2fdxdy_bkwdfwd << " d2f/dx dy=" << d2fdxdy_fwdfwd << " error=" << round_error(d2fdxdy_bkwdfwd - d2fdxdy_fwdfwd) << std::endl;


}

void simple_example4()
{
    qrecorder<__m256d> rec;

    double S0v = 100.0;
    double Kv = 110.0;
    double rv = 0.1;
    double volv = 0.25;
    double Tv = 1.0;

    qdouble S0;

    rec.start();

    qdouble K, r, vol, T, unused, BS;

    S0 = S0v;
    K = Kv;
    r = rv;
    vol = volv;
    T = Tv;

    rec.input(S0);
    rec.input(K);
    rec.input(r);
    rec.input(vol);
    //    rec.input(T);

   //    BS = BlackScholes(S0, K, r, vol, T, unused);
   //    BS = BlackScholes(S0, K, r, vol, T);

   //    qdouble BS = 0.5 * (std::log(S0/K));

   //    qdouble BS = std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
   //        T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T)));

    BS = BlackScholes(S0, K, r, vol, T);

    rec.output(BS);

    rec.stop();

    auto g = rec.graph();

    auto dg = g.backwardAD();

    auto ws = dg.workspace();

    ws.set_adjoint(BS, 1.0);

    dg.run(ws);

    auto value = ws.get_value(BS);
    auto dBSdS0 = ws.get_adjoint(S0);
    auto dBSdK = ws.get_adjoint(K);
    auto dBSdr = ws.get_adjoint(r);
    auto dBSdvol = ws.get_adjoint(vol);

    // Calc closed form

    double dBSdS0_actual, dBSdK_actual, dBSdr_actual, dBSdvol_actual;
    double d2BSdS02_actual, d2BSdKdS0_actual, d2BSdrdS0_actual, d2BSdvoldS0_actual;
    double d3BSdS03_actual;

    double BS_actual = BlackScholes_closedform(S0v,Kv,rv,volv,Tv,
        dBSdS0_actual,dBSdK_actual,dBSdr_actual,dBSdvol_actual, 
        d2BSdS02_actual, d2BSdKdS0_actual, d2BSdrdS0_actual, d2BSdvoldS0_actual, d3BSdS03_actual);

    double BS_calc = *(double*)&value;
    double dBSdS0_calc = *(double*)&dBSdS0;
    double dBSdK_calc = *(double*)&dBSdK;
    double dBSdr_calc = *(double*)&dBSdr;
    double dBSdvol_calc = *(double*)&dBSdvol;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;
    std::cout << "dBS/dK=" << dBSdK_calc << " dBS/dK_actual=" << dBSdK_actual << " error=" << round_error(dBSdK_actual- dBSdK_calc) << std::endl;
    std::cout << "dBS/dr=" << dBSdr_calc << " dBS/dr_actual=" << dBSdr_actual << " error=" << round_error(dBSdr_actual - dBSdr_calc) << std::endl;
    std::cout << "dBS/dvol=" << dBSdvol_calc << " dBS/dvol_actual=" << dBSdvol_actual << " error=" << round_error(dBSdvol_actual - dBSdvol_calc) << std::endl;

    auto dg2 = dg.forwardAD();

    auto ws2 = dg2.workspace();

    ws2.set_adjoint(BS, 1.0);
    ws2.set_dual(S0, 1.0, 2);

    dg2.run(ws2);

    value = ws2.get_value(BS);
    dBSdS0 = ws2.get_adjoint(S0);
    dBSdK = ws2.get_adjoint(K);
    dBSdr = ws2.get_adjoint(r);
    dBSdvol = ws2.get_adjoint(vol);
    auto d2BSdS02 = ws2.get_dual(S0, 2);
    auto d2BSdKdS0 = ws2.get_dual(K, 2);
    auto d2BSdrdS0 = ws2.get_dual(r, 2);
    auto d2BSdvoldS0 = ws2.get_dual(vol, 2);

    BS_calc = *(double*)&value;
    dBSdS0_calc = *(double*)&dBSdS0;
    dBSdK_calc = *(double*)&dBSdK;
    dBSdr_calc = *(double*)&dBSdr;
    dBSdvol_calc = *(double*)&dBSdvol;
    double d2BSdS02_calc = *(double*)&d2BSdS02;
    double d2BSdKdS0_calc = *(double*)&d2BSdKdS0;
    double d2BSdrdS0_calc = *(double*)&d2BSdrdS0;
    double d2BSdvoldS0_calc = *(double*)&d2BSdvoldS0;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;
    std::cout << "dBS/dK=" << dBSdK_calc << " dBS/dK_actual=" << dBSdK_actual << " error=" << round_error(dBSdK_actual - dBSdK_calc) << std::endl;
    std::cout << "dBS/dr=" << dBSdr_calc << " dBS/dr_actual=" << dBSdr_actual << " error=" << round_error(dBSdr_actual - dBSdr_calc) << std::endl;
    std::cout << "dBS/dvol=" << dBSdvol_calc << " dBS/dvol_actual=" << dBSdvol_actual << " error=" << round_error(dBSdvol_actual - dBSdvol_calc) << std::endl;
    std::cout << "d2BS/dS0^2=" << d2BSdS02_calc << " d2BS/dS0^2_actual=" << d2BSdS02_actual << " error=" << round_error(d2BSdS02_calc - d2BSdS02_actual) << std::endl;
    std::cout << "d2BS/dK dS0=" << d2BSdKdS0_calc << " d2BS/dK dS0_actual=" << d2BSdKdS0_actual << " error=" << round_error(d2BSdKdS0_calc - d2BSdKdS0_actual) << std::endl;
    std::cout << "d2BS/dr dS0=" << d2BSdrdS0_calc << " d2BS/dr dS0_actual=" << d2BSdrdS0_actual << " error=" << round_error(d2BSdrdS0_calc - d2BSdrdS0_actual) << std::endl;
    std::cout << "d2BS/dvol dS0=" << d2BSdvoldS0_calc << " d2BS/dvol dS0_actual=" << d2BSdvoldS0_actual << " error=" << round_error(d2BSdvoldS0_calc - d2BSdvoldS0_actual) << std::endl;

    auto dg3 = dg2.forwardAD();

    auto ws3 = dg3.workspace();

    ws3.set_adjoint(BS, 1.0);
    ws3.set_dual(S0, 1.0, 2);
    ws3.set_dual(S0, 1.0, 3);

    dg3.run(ws3);

    value = ws3.get_value(BS);
    dBSdS0 = ws3.get_adjoint(S0);
    dBSdK = ws3.get_adjoint(K);
    dBSdr = ws3.get_adjoint(r);
    dBSdvol = ws3.get_adjoint(vol);
    d2BSdS02 = ws3.get_dual(S0, 2);
    d2BSdKdS0 = ws3.get_dual(K, 2);
    d2BSdrdS0 = ws3.get_dual(r, 2);
    d2BSdvoldS0 = ws3.get_dual(vol, 2);
    auto d3BSdS03 = ws3.get_dual(S0, 3);
    auto d3BSdKdS02 = ws3.get_dual(K, 3);
    auto d3BSdrdS02 = ws3.get_dual(r, 3);
    auto d3BSdvoldS02 = ws3.get_dual(vol, 3);

    BS_calc = *(double*)&value;
    dBSdS0_calc = *(double*)&dBSdS0;
    dBSdK_calc = *(double*)&dBSdK;
    dBSdr_calc = *(double*)&dBSdr;
    dBSdvol_calc = *(double*)&dBSdvol;
    d2BSdS02_calc = *(double*)&d2BSdS02;
    d2BSdKdS0_calc = *(double*)&d2BSdKdS0;
    d2BSdrdS0_calc = *(double*)&d2BSdrdS0;
    d2BSdvoldS0_calc = *(double*)&d2BSdvoldS0;

    auto d3BSdS03_calc = *(double*)&d3BSdS03;
    auto d3BSdKdS02_calc = *(double*)&d3BSdKdS02;
    auto d3BSdrdS02_calc = *(double*)&d3BSdrdS02;
    auto d3BSdvoldS02_calc = *(double*)&d3BSdvoldS02;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;
    std::cout << "dBS/dK=" << dBSdK_calc << " dBS/dK_actual=" << dBSdK_actual << " error=" << round_error(dBSdK_actual - dBSdK_calc) << std::endl;
    std::cout << "dBS/dr=" << dBSdr_calc << " dBS/dr_actual=" << dBSdr_actual << " error=" << round_error(dBSdr_actual - dBSdr_calc) << std::endl;
    std::cout << "dBS/dvol=" << dBSdvol_calc << " dBS/dvol_actual=" << dBSdvol_actual << " error=" << round_error(dBSdvol_actual - dBSdvol_calc) << std::endl;
    std::cout << "d2BS/dS0^2=" << d2BSdS02_calc << " d2BS/dS0^2_actual=" << d2BSdS02_actual << " error=" << round_error(d2BSdS02_calc - d2BSdS02_actual) << std::endl;
    std::cout << "d2BS/dK dS0=" << d2BSdKdS0_calc << " d2BS/dK dS0_actual=" << d2BSdKdS0_actual << " error=" << round_error(d2BSdKdS0_calc - d2BSdKdS0_actual) << std::endl;
    std::cout << "d2BS/dr dS0=" << d2BSdrdS0_calc << " d2BS/dr dS0_actual=" << d2BSdrdS0_actual << " error=" << round_error(d2BSdrdS0_calc - d2BSdrdS0_actual) << std::endl;
    std::cout << "d2BS/dvol dS0=" << d2BSdvoldS0_calc << " d2BS/dvol dS0_actual=" << d2BSdvoldS0_actual << " error=" << round_error(d2BSdvoldS0_calc - d2BSdvoldS0_actual) << std::endl;
    std::cout << "d3BS/dS0^3=" << d3BSdS03_calc << " d3BS/dS0^3_actual=" << d3BSdS03_actual << " error=" << round_error(d3BSdS03_calc - d3BSdS03_actual) << std::endl;
    std::cout << "d3BS/dK dS02=" << d3BSdKdS02_calc << std::endl;
    std::cout << "d3BS/dr dS02=" << d3BSdrdS02_calc << std::endl;
    std::cout << "d3BS/dvol dS02=" << d3BSdvoldS02_calc << std::endl;

    // Let us now do forward and then backward

    dg2 = g.forwardAD().backwardAD();

    ws2 = dg2.workspace();

    ws2.set_dual(S0, 1.0);
    ws2.set_adjoint(BS, 1.0, 2);

    dg2.run(ws2);

    auto res = ws2.get_value(BS);
    auto e0 = ws2.get_dual(BS);
    auto e1 = ws2.get_adjoint(S0,2);

    dg2 = g.backwardAD().forwardAD();

    ws2 = dg2.workspace();

    ws2.set_adjoint(BS, 1.0);
    ws2.set_dual(S0, 1.0, 2);

    dg2.run(ws2);

    res = ws2.get_value(BS);
    e0 = ws2.get_adjoint(S0);
    e1 = ws2.get_dual(S0, 2);

}

void simple_example4_idx()
{
    qrecorder<__m256d> rec;

    double S0v = 100.0;
    double Kv = 110.0;
    double rv = 0.1;
    double volv = 0.25;
    double Tv = 1.0;

    qdouble S0;

    rec.start();

    qdouble K, r, vol, T, unused, BS;

    S0 = S0v;
    K = Kv;
    r = rv;
    vol = volv;
    T = Tv;

    rec.input(S0);
    rec.input(K);
    rec.input(r);
    rec.input(vol);
    //    rec.input(T);

   //    BS = BlackScholes(S0, K, r, vol, T, unused);
   //    BS = BlackScholes(S0, K, r, vol, T);

   //    qdouble BS = 0.5 * (std::log(S0/K));

   //    qdouble BS = std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
   //        T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T)));

    BS = BlackScholes(S0, K, r, vol, T);

    rec.output(BS);

    rec.stop();

    auto g = rec.graph();

    auto dg = g.backwardAD();

    auto ws = dg.workspace();

    uint64_t BSi = ws.get_index(BS);
    uint64_t S0i = ws.get_index(S0);
    uint64_t Ki = ws.get_index(K);
    uint64_t ri = ws.get_index(r);
    uint64_t voli = ws.get_index(vol);

    ws.set_adjoint(BSi, 1.0);

    dg.run(ws);

    auto value = ws.get_value(BSi);
    auto dBSdS0 = ws.get_adjoint(S0i);
    auto dBSdK = ws.get_adjoint(Ki);
    auto dBSdr = ws.get_adjoint(ri);
    auto dBSdvol = ws.get_adjoint(voli);

    // Calc closed form

    double dBSdS0_actual, dBSdK_actual, dBSdr_actual, dBSdvol_actual;
    double d2BSdS02_actual, d2BSdKdS0_actual, d2BSdrdS0_actual, d2BSdvoldS0_actual;
    double d3BSdS03_actual;

    double BS_actual = BlackScholes_closedform(S0v, Kv, rv, volv, Tv,
        dBSdS0_actual, dBSdK_actual, dBSdr_actual, dBSdvol_actual,
        d2BSdS02_actual, d2BSdKdS0_actual, d2BSdrdS0_actual, d2BSdvoldS0_actual, d3BSdS03_actual);

    double BS_calc = *(double*)&value;
    double dBSdS0_calc = *(double*)&dBSdS0;
    double dBSdK_calc = *(double*)&dBSdK;
    double dBSdr_calc = *(double*)&dBSdr;
    double dBSdvol_calc = *(double*)&dBSdvol;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;
    std::cout << "dBS/dK=" << dBSdK_calc << " dBS/dK_actual=" << dBSdK_actual << " error=" << round_error(dBSdK_actual - dBSdK_calc) << std::endl;
    std::cout << "dBS/dr=" << dBSdr_calc << " dBS/dr_actual=" << dBSdr_actual << " error=" << round_error(dBSdr_actual - dBSdr_calc) << std::endl;
    std::cout << "dBS/dvol=" << dBSdvol_calc << " dBS/dvol_actual=" << dBSdvol_actual << " error=" << round_error(dBSdvol_actual - dBSdvol_calc) << std::endl;

    auto dg2 = dg.forwardAD();

    auto ws2 = dg2.workspace();

    BSi = ws2.get_index(BS);
    S0i = ws2.get_index(S0);
    Ki = ws2.get_index(K);
    ri = ws2.get_index(r);
    voli = ws2.get_index(vol);

    ws2.set_adjoint(BSi, 1.0);
    ws2.set_dual(S0i, 1.0, 2);

    dg2.run(ws2);

    value = ws2.get_value(BSi);
    dBSdS0 = ws2.get_adjoint(S0i);
    dBSdK = ws2.get_adjoint(Ki);
    dBSdr = ws2.get_adjoint(ri);
    dBSdvol = ws2.get_adjoint(voli);
    auto d2BSdS02 = ws2.get_dual(S0i, 2);
    auto d2BSdKdS0 = ws2.get_dual(Ki, 2);
    auto d2BSdrdS0 = ws2.get_dual(ri, 2);
    auto d2BSdvoldS0 = ws2.get_dual(voli, 2);

    BS_calc = *(double*)&value;
    dBSdS0_calc = *(double*)&dBSdS0;
    dBSdK_calc = *(double*)&dBSdK;
    dBSdr_calc = *(double*)&dBSdr;
    dBSdvol_calc = *(double*)&dBSdvol;
    double d2BSdS02_calc = *(double*)&d2BSdS02;
    double d2BSdKdS0_calc = *(double*)&d2BSdKdS0;
    double d2BSdrdS0_calc = *(double*)&d2BSdrdS0;
    double d2BSdvoldS0_calc = *(double*)&d2BSdvoldS0;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;
    std::cout << "dBS/dK=" << dBSdK_calc << " dBS/dK_actual=" << dBSdK_actual << " error=" << round_error(dBSdK_actual - dBSdK_calc) << std::endl;
    std::cout << "dBS/dr=" << dBSdr_calc << " dBS/dr_actual=" << dBSdr_actual << " error=" << round_error(dBSdr_actual - dBSdr_calc) << std::endl;
    std::cout << "dBS/dvol=" << dBSdvol_calc << " dBS/dvol_actual=" << dBSdvol_actual << " error=" << round_error(dBSdvol_actual - dBSdvol_calc) << std::endl;
    std::cout << "d2BS/dS0^2=" << d2BSdS02_calc << " d2BS/dS0^2_actual=" << d2BSdS02_actual << " error=" << round_error(d2BSdS02_calc - d2BSdS02_actual) << std::endl;
    std::cout << "d2BS/dK dS0=" << d2BSdKdS0_calc << " d2BS/dK dS0_actual=" << d2BSdKdS0_actual << " error=" << round_error(d2BSdKdS0_calc - d2BSdKdS0_actual) << std::endl;
    std::cout << "d2BS/dr dS0=" << d2BSdrdS0_calc << " d2BS/dr dS0_actual=" << d2BSdrdS0_actual << " error=" << round_error(d2BSdrdS0_calc - d2BSdrdS0_actual) << std::endl;
    std::cout << "d2BS/dvol dS0=" << d2BSdvoldS0_calc << " d2BS/dvol dS0_actual=" << d2BSdvoldS0_actual << " error=" << round_error(d2BSdvoldS0_calc - d2BSdvoldS0_actual) << std::endl;

    auto dg3 = dg2.forwardAD();

    auto ws3 = dg3.workspace();

    BSi = ws3.get_index(BS);
    S0i = ws3.get_index(S0);
    Ki = ws3.get_index(K);
    ri = ws3.get_index(r);
    voli = ws3.get_index(vol);

    ws3.set_adjoint(BSi, 1.0);
    ws3.set_dual(S0i, 1.0, 2);
    ws3.set_dual(S0i, 1.0, 3);

    dg3.run(ws3);

    value = ws3.get_value(BSi);
    dBSdS0 = ws3.get_adjoint(S0i);
    dBSdK = ws3.get_adjoint(Ki);
    dBSdr = ws3.get_adjoint(ri);
    dBSdvol = ws3.get_adjoint(voli);
    d2BSdS02 = ws3.get_dual(S0i, 2);
    d2BSdKdS0 = ws3.get_dual(Ki, 2);
    d2BSdrdS0 = ws3.get_dual(ri, 2);
    d2BSdvoldS0 = ws3.get_dual(voli, 2);
    auto d3BSdS03 = ws3.get_dual(S0i, 3);
    auto d3BSdKdS02 = ws3.get_dual(Ki, 3);
    auto d3BSdrdS02 = ws3.get_dual(ri, 3);
    auto d3BSdvoldS02 = ws3.get_dual(voli, 3);

    BS_calc = *(double*)&value;
    dBSdS0_calc = *(double*)&dBSdS0;
    dBSdK_calc = *(double*)&dBSdK;
    dBSdr_calc = *(double*)&dBSdr;
    dBSdvol_calc = *(double*)&dBSdvol;
    d2BSdS02_calc = *(double*)&d2BSdS02;
    d2BSdKdS0_calc = *(double*)&d2BSdKdS0;
    d2BSdrdS0_calc = *(double*)&d2BSdrdS0;
    d2BSdvoldS0_calc = *(double*)&d2BSdvoldS0;

    auto d3BSdS03_calc = *(double*)&d3BSdS03;
    auto d3BSdKdS02_calc = *(double*)&d3BSdKdS02;
    auto d3BSdrdS02_calc = *(double*)&d3BSdrdS02;
    auto d3BSdvoldS02_calc = *(double*)&d3BSdvoldS02;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;
    std::cout << "dBS/dK=" << dBSdK_calc << " dBS/dK_actual=" << dBSdK_actual << " error=" << round_error(dBSdK_actual - dBSdK_calc) << std::endl;
    std::cout << "dBS/dr=" << dBSdr_calc << " dBS/dr_actual=" << dBSdr_actual << " error=" << round_error(dBSdr_actual - dBSdr_calc) << std::endl;
    std::cout << "dBS/dvol=" << dBSdvol_calc << " dBS/dvol_actual=" << dBSdvol_actual << " error=" << round_error(dBSdvol_actual - dBSdvol_calc) << std::endl;
    std::cout << "d2BS/dS0^2=" << d2BSdS02_calc << " d2BS/dS0^2_actual=" << d2BSdS02_actual << " error=" << round_error(d2BSdS02_calc - d2BSdS02_actual) << std::endl;
    std::cout << "d2BS/dK dS0=" << d2BSdKdS0_calc << " d2BS/dK dS0_actual=" << d2BSdKdS0_actual << " error=" << round_error(d2BSdKdS0_calc - d2BSdKdS0_actual) << std::endl;
    std::cout << "d2BS/dr dS0=" << d2BSdrdS0_calc << " d2BS/dr dS0_actual=" << d2BSdrdS0_actual << " error=" << round_error(d2BSdrdS0_calc - d2BSdrdS0_actual) << std::endl;
    std::cout << "d2BS/dvol dS0=" << d2BSdvoldS0_calc << " d2BS/dvol dS0_actual=" << d2BSdvoldS0_actual << " error=" << round_error(d2BSdvoldS0_calc - d2BSdvoldS0_actual) << std::endl;
    std::cout << "d3BS/dS0^3=" << d3BSdS03_calc << " d3BS/dS0^3_actual=" << d3BSdS03_actual << " error=" << round_error(d3BSdS03_calc - d3BSdS03_actual) << std::endl;
    std::cout << "d3BS/dK dS02=" << d3BSdKdS02_calc << std::endl;
    std::cout << "d3BS/dr dS02=" << d3BSdrdS02_calc << std::endl;
    std::cout << "d3BS/dvol dS02=" << d3BSdvoldS02_calc << std::endl;

    // Let us now do forward and then backward

    dg2 = g.forwardAD().backwardAD();

    ws2 = dg2.workspace();

    BSi = ws2.get_index(BS);
    S0i = ws2.get_index(S0);
    Ki = ws2.get_index(K);
    ri = ws2.get_index(r);
    voli = ws2.get_index(vol);

    ws2.set_dual(S0i, 1.0);
    ws2.set_adjoint(BSi, 1.0, 2);

    dg2.run(ws2);

    auto res = ws2.get_value(BSi);
    auto e0 = ws2.get_dual(BSi);
    auto e1 = ws2.get_adjoint(S0i, 2);

    dg2 = g.backwardAD().forwardAD();

    ws2 = dg2.workspace();

    BSi = ws2.get_index(BS);
    S0i = ws2.get_index(S0);
    Ki = ws2.get_index(K);
    ri = ws2.get_index(r);
    voli = ws2.get_index(vol);

    ws2.set_adjoint(BSi, 1.0);
    ws2.set_dual(S0i, 1.0, 2);

    dg2.run(ws2);

    res = ws2.get_value(BSi);
    e0 = ws2.get_adjoint(S0i);
    e1 = ws2.get_dual(S0i, 2);

}


void simple_example5()
{
    qrecorder<double*> rec;

    double S0v = 100.0;
    double Kv = 110.0;
    double rv = 0.1;
    double volv = 0.25;
    double Tv = 1.0;

    qdouble S0;

    rec.start();

    qdouble K, r, vol, T, unused, BS;

    S0 = S0v;
    K = Kv;
    r = rv;
    vol = volv;
    T = Tv;

    rec.input(S0);
    rec.input(K);
    rec.input(r);
    rec.input(vol);
    //    rec.input(T);

    BS = BlackScholes(S0, K, r, vol, T);

    rec.output(BS);

    rec.stop();

    auto g = rec.graph();

    auto ws = g.workspace();

    g.allocate(ws,100);

    g.run(ws);

    auto res = ws.get_value(BS);


}

#include "qboolean.h"
#include "qinteger.h"
#include "qalgorithm.h"

#include <vector>
#include "qstream.h"

void simple_example6()
{
    qrecorder<__m256d> r;

    qfloat x(1.0);
    qbool b = true;

    r.start();

    r.input(x);

//    auto y = qif(b && x > 1.0, x, x * x);

    auto y = qif(x > 1.0, x, x * x);

    r.output(y);

    r.stop();

    auto g = r.graph();

    auto ws = g.workspace();

//    g.run(ws);

//    auto res = ws.get_value(y);


}

#include "qutils.h"

int main()
{
#ifndef main
    std::cout << "Computer has " << gpu_info::num_nvidia() << " NVIDIA GPU" << std::endl;
    std::cout << "Computer has " << gpu_info::num_amd() << " AMD GPU" << std::endl;
    std::cout << "CPU " << (cpu_info::has_avx512() ? "has" : "does not have") << " AVX512" << std::endl;
#endif

//    simple_example6();
    {
        qscalar<__m256d> s1({ 1,2,3,4 });
        qscalar<__m256d> s2({ 2,3,4,5 });
        qscalar<__m256d> s3({ 6,7,9,10 });

        std::vector<qscalar<__m256d>> v;

        v.push_back(s1);
        v.push_back(s2);
        v.push_back(s3);

        qscalar<__m256d> x({1.5,3.5,8.8,3.1});

        auto it = qlower_bound(v.begin(), v.end(), x);

        auto j = it - v.begin();

        std::cout << j << " " << *it << std::endl;

        std::vector<double> v2({1,2,10});

        auto jt = qlower_bound(v2.begin(), v2.end(), x);

        std::cout << (jt-v2.begin()) << " " << *jt << std::endl;

    }

    {
        std::vector<qscalar<__m256d>> v1(5, _mm256_set1_pd(1.0));
        std::vector<__m256d> v2(5, _mm256_set1_pd(2.0));
        std::vector<double> v3(2,3.0);
        qscalar<__m256d> xm(1.0);
        qdouble x(1.0);

        qlower_bound(v1.begin(), v1.end(), _mm256_set1_pd(1.0))-v1.begin();
        qlower_bound(v3.begin(), v3.end(), x)-v3.begin();
        qlower_bound(v2.begin(), v2.end(), xm)-v2.begin();
        qlower_bound(v3.begin(), v3.end(), xm)-v3.begin();

        qmax_element(v1.begin(), v1.end());

        qlower_bound(v1.begin(), v1.end(), _mm256_set1_pd(1.0), [&](const qscalar<__m256d>& x, const qscalar<__m256d>& y) { return x < y; });

    }
    {
        qint z(1);
        qbool b(true);
        qbool b2({ true });
        qboolean<__m256d> b256d({ true, false, false, true });
        qboolean<__m256d> b256d2(true);
        for (uint64_t i = 0; i < 4; ++i)
            std::cout << b256d[i] << std::endl;
        std::cout << b256d[1] << " " << b[0] << std::endl;
        bool duc = b256d[1] = b[0] = true;
        std::cout << b256d[1] << " " << b[0] << " " << duc << std::endl;
        auto b3 = b256d && b256d2;
        auto b4 = b256d && true;
        auto b5 = true && b256d;
        auto b6 = b && true;
        auto b7 = b && b;
        auto b8 = true && !b;
        qdouble x = 1.0, y = 2.0;
        auto x1 = qif(x > y, true, b8);
        qscalar<__m256d> xm(1.0);
        qscalar<__m256d> ym(2.0);
        auto x2 = qif(xm > ym, !b5, b4);
        auto x3 = qif(xm > 4.0, !b5, b4);
        auto x4 = qif(xm > _mm256_set_pd(4.0, 1.2, 3.4, 5.2), !b5, b4);
    }

    simple_example5();
    simple_example4_idx();
    simple_example4();
    simple_example3();
    simple_example2();
    //    return 0;

    double S0v = 100.0;
    double Kv = 110.0;
    double rv = 0.1;
    double volv = 0.25;
    double Tv = 1.0;

    double dBSdS0_actual, dBSdK_actual, dBSdr_actual, dBSdvol_actual;
    double d2BSdS02_actual, d2BSdKdS0_actual, d2BSdrdS0_actual, d2BSdvoldS0_actual;
    double d3BSdS03_actual;

    double BS_actual = BlackScholes_closedform(S0v, Kv, rv, volv, Tv,
        dBSdS0_actual, dBSdK_actual, dBSdr_actual, dBSdvol_actual,
        d2BSdS02_actual, d2BSdKdS0_actual, d2BSdrdS0_actual, d2BSdvoldS0_actual, d3BSdS03_actual);

    qrecorder<__m256d> rec;

    qdouble S0;

    rec.start();

    qdouble K, r, vol, T, unused, BS;

    S0 = S0v;
    K = Kv;
    r = rv;
    vol = volv;
    T = Tv;

    S0[0];

    rec.input(S0);
    rec.input(K);
    rec.input(r);
    rec.input(vol);
 //    rec.input(T);

//    BS = BlackScholes(S0, K, r, vol, T, unused);
//    BS = BlackScholes(S0, K, r, vol, T);

//    qdouble BS = 0.5 * (std::log(S0/K));

//    qdouble BS = std::exp(-r * T) * K * std::normal_cdf((std::log(S0 / K) +
//        T * (r - 0.5 * (std::pow(vol, 2)))) / (vol * std::sqrt(T)));

    BS = BlackScholes(S0, K, r, vol, T);

    rec.output(BS);

    rec.stop();

    auto g = rec.graph();

    auto ws = g.workspace();

//    ws.set_value(S0, 120);

    g.run(ws);

    auto value = ws.get_value(BS);

    double BS_calc = *(double*)&value;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;

    auto dg = g.forwardAD();

    auto wsd = dg.workspace();

    wsd.set_dual(S0,1.0);

    dg.run(wsd);

    auto res0 = wsd.get_value(BS);
    auto res1 = wsd.get_dual(BS);

    BS_calc = *(double*)&res0;
    double dBSdS0_calc = *(double*)&res1;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;

    auto dg2 = dg.forwardAD();

    auto ws2 = dg2.workspace();

    ws2.set_dual(S0, 1.0);
    ws2.set_dual(S0, 1.0, 2);

    dg2.run(ws2);

    auto c0 = ws2.get_value(BS);
    auto c1 = ws2.get_dual(BS);
    auto c2 = ws2.get_dual(BS,2);

    BS_calc = *(double*)&c0;
    dBSdS0_calc = *(double*)&c1;
    double d2BSdS02_calc = *(double*)&c2;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;
    std::cout << "d2BS/dS0^2=" << d2BSdS02_calc << " d2BS/dS0^2_actual=" << d2BSdS02_actual << " error=" << round_error(d2BSdS02_calc - d2BSdS02_actual) << std::endl;

    // Let us try a cross

    ws2.set_dual(S0, 1.0);
    ws2.set_dual(S0, 0.0, 2);
    ws2.set_dual(K, 0.0);
    ws2.set_dual(K, 1.0, 2);

    dg2.run(ws2);

    c0 = ws2.get_value(BS);
    c1 = ws2.get_dual(BS);
    c2 = ws2.get_dual(BS, 2);

    BS_calc = *(double*)&c0;
    dBSdS0_calc = *(double*)&c1;
    double d2BSdKdS0_calc = *(double*)&c2;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;
    std::cout << "d2BS/dK dS0=" << d2BSdKdS0_calc << " d2BS/dK dS0_actual=" << d2BSdKdS0_actual << " error=" << round_error(d2BSdKdS0_calc - d2BSdKdS0_actual) << std::endl;

    // Let us try the cross a different way 

    ws2.set_dual(S0, 0.0);
    ws2.set_dual(S0, 1.0, 2);
    ws2.set_dual(K, 1.0);
    ws2.set_dual(K, 0.0, 2);

    dg2.run(ws2);

    c0 = ws2.get_value(BS);
    c1 = ws2.get_dual(BS);
    c2 = ws2.get_dual(BS, 2);

    BS_calc = *(double*)&c0;
    double dBSdK_calc = *(double*)&c1;
    d2BSdKdS0_calc = *(double*)&c2;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dK=" << dBSdK_calc << " dBS/dK_actual=" << dBSdK_actual << " error=" << round_error(dBSdK_actual - dBSdK_calc) << std::endl;
    std::cout << "d2BS/dK dS0=" << d2BSdKdS0_calc << " d2BS/dK dS0_actual=" << d2BSdKdS0_actual << " error=" << round_error(d2BSdKdS0_calc - d2BSdKdS0_actual) << std::endl;

    // 3rd order

    auto dg3 = dg2.forwardAD();
    auto ws3 = dg3.workspace();
    ws3.set_dual(S0, 1.0);
    ws3.set_dual(S0, 1.0, 2);
    ws3.set_dual(S0, 1.0, 3);

    dg3.run(ws3);

    auto d0 = ws3.get_value(BS);
    auto d1 = ws3.get_dual(BS);
    auto d2 = ws3.get_dual(BS, 2);
    auto d3 = ws3.get_dual(BS, 3);

    BS_calc = *(double*)&d0;
    dBSdS0_calc = *(double*)&d1;
    d2BSdS02_calc = *(double*)&d2;
    double d3BSdS03_calc = *(double*)&d3;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;
    std::cout << "d2BS/dS0^2=" << d2BSdS02_calc << " d2BS/dS0^2_actual=" << d2BSdS02_actual << " error=" << round_error(d2BSdS02_calc - d2BSdS02_actual) << std::endl;
    std::cout << "d3BS/dS0^3=" << d3BSdS03_calc << " d3BS/dS0^3_actual=" << d3BSdS03_actual << " error=" << round_error(d3BSdS03_calc - d3BSdS03_actual) << std::endl;

    // Fourth order

    auto dg4 = dg3.forwardAD();
    auto ws4 = dg4.workspace();
    ws4.set_dual(S0, 1.0);
    ws4.set_dual(S0, 1.0, 2);
    ws4.set_dual(S0, 1.0, 3);
    ws4.set_dual(S0, 1.0, 4);

    dg4.run(ws4);

    auto e0 = ws4.get_value(BS);
    auto e1 = ws4.get_dual(BS);
    auto e2 = ws4.get_dual(BS, 2);
    auto e3 = ws4.get_dual(BS, 3);
    auto e4 = ws4.get_dual(BS, 4);

    BS_calc = *(double*)&e0;
    dBSdS0_calc = *(double*)&e1;
    d2BSdS02_calc = *(double*)&e2;
    d3BSdS03_calc = *(double*)&e3;
    double d4BSdS04_calc = *(double*)&e4;

    std::cout << "BS=" << BS_calc << " " << "BS_actual=" << BS_actual << " error=" << round_error(BS_actual - BS_calc) << std::endl;
    std::cout << "dBS/dS0=" << dBSdS0_calc << " dBS/dS0_actual=" << dBSdS0_actual << " error=" << round_error(dBSdS0_actual - dBSdS0_calc) << std::endl;
    std::cout << "d2BS/dS0^2=" << d2BSdS02_calc << " d2BS/dS0^2_actual=" << d2BSdS02_actual << " error=" << round_error(d2BSdS02_calc - d2BSdS02_actual) << std::endl;
    std::cout << "d3BS/dS0^3=" << d3BSdS03_calc << " d3BS/dS0^3_actual=" << d3BSdS03_actual << " error=" << round_error(d3BSdS03_calc - d3BSdS03_actual) << std::endl;
    std::cout << "d4BS/dS0^4=" << *(double*)&e4 << std::endl;

    return 0;
}
