% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 657.462363451965530 ; 657.946041818133950 ];

%-- Principal point:
cc = [ 303.137426942334970 ; 242.569925507730570 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.254025214224612 ; 0.121427630155799 ; -0.000208723296698 ; 0.000019601032322 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 0.318170395167335 ; 0.340443470630650 ];

%-- Principal point uncertainty:
cc_error = [ 0.646783496050558 ; 0.592150774602891 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.002482597545034 ; 0.009863106652478 ; 0.000133833073482 ; 0.000132166390380 ; 0.000000000000000 ];

%-- Image size:
nx = 640;
ny = 480;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 20;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 2.420239e-03 ; 2.723944e+00 ; -1.293323e+00 ];
Tc_1  = [ 1.793631e+02 ; -6.496257e+01 ; 8.943269e+02 ];
omc_error_1 = [ 6.910212e-04 ; 1.171374e-03 ; 1.434524e-03 ];
Tc_error_1  = [ 8.804268e-01 ; 8.140968e-01 ; 4.340653e-01 ];

%-- Image #2:
omc_2 = [ -4.009130e-02 ; 2.915376e+00 ; -7.968315e-01 ];
Tc_2  = [ 2.022156e+02 ; -1.390287e+02 ; 7.963730e+02 ];
omc_error_2 = [ 5.049199e-04 ; 1.204200e-03 ; 1.655197e-03 ];
Tc_error_2  = [ 7.871704e-01 ; 7.267577e-01 ; 4.373261e-01 ];

%-- Image #3:
omc_3 = [ -2.637173e-01 ; 3.005909e+00 ; -8.183149e-01 ];
Tc_3  = [ 2.295136e+02 ; -1.148982e+02 ; 7.649226e+02 ];
omc_error_3 = [ 5.652656e-04 ; 1.183703e-03 ; 1.729947e-03 ];
Tc_error_3  = [ 7.559290e-01 ; 6.989212e-01 ; 4.520927e-01 ];

%-- Image #4:
omc_4 = [ 1.882619e-01 ; -2.572258e+00 ; 8.516952e-01 ];
Tc_4  = [ 2.600624e+02 ; -1.563970e+02 ; 6.234678e+02 ];
omc_error_4 = [ 5.091775e-04 ; 1.079112e-03 ; 1.370698e-03 ];
Tc_error_4  = [ 6.206863e-01 ; 5.814046e-01 ; 4.541473e-01 ];

%-- Image #5:
omc_5 = [ -6.575786e-01 ; 2.341251e+00 ; -1.057497e+00 ];
Tc_5  = [ 1.836086e+02 ; -1.315922e+01 ; 8.193682e+02 ];
omc_error_5 = [ 7.920517e-04 ; 9.749880e-04 ; 1.234034e-03 ];
Tc_error_5  = [ 8.109525e-01 ; 7.393031e-01 ; 3.896881e-01 ];

%-- Image #6:
omc_6 = [ -1.781942e-01 ; 2.840348e+00 ; 1.101724e+00 ];
Tc_6  = [ 2.071464e+02 ; -5.231159e+01 ; 4.899751e+02 ];
omc_error_6 = [ 5.987497e-04 ; 1.104631e-03 ; 1.420317e-03 ];
Tc_error_6  = [ 4.848106e-01 ; 4.546881e-01 ; 3.702806e-01 ];

%-- Image #7:
omc_7 = [ 3.922340e-02 ; 2.367859e+00 ; 7.256304e-01 ];
Tc_7  = [ 2.001572e+02 ; -1.525617e+02 ; 6.494710e+02 ];
omc_error_7 = [ 6.235346e-04 ; 1.040452e-03 ; 1.165406e-03 ];
Tc_error_7  = [ 6.404450e-01 ; 5.948177e-01 ; 4.107476e-01 ];

%-- Image #8:
omc_8 = [ 8.298815e-02 ; 2.294281e+00 ; 6.656748e-01 ];
Tc_8  = [ 9.216240e+01 ; -1.927712e+02 ; 6.918206e+02 ];
omc_error_8 = [ 5.844562e-04 ; 1.015270e-03 ; 1.142474e-03 ];
Tc_error_8  = [ 6.850906e-01 ; 6.257938e-01 ; 3.926756e-01 ];

%-- Image #9:
omc_9 = [ 4.393244e-01 ; -2.381757e+00 ; -4.174923e-01 ];
Tc_9  = [ 2.566583e+02 ; -7.581630e+01 ; 5.274056e+02 ];
omc_error_9 = [ 5.242398e-04 ; 1.125603e-03 ; 1.282545e-03 ];
Tc_error_9  = [ 5.513517e-01 ; 5.060882e-01 ; 5.100436e-01 ];

%-- Image #10:
omc_10 = [ 4.120912e-01 ; -2.585988e+00 ; -3.953810e-01 ];
Tc_10  = [ 2.710391e+02 ; -1.721539e+02 ; 7.093474e+02 ];
omc_error_10 = [ 4.810309e-04 ; 1.382989e-03 ; 1.701584e-03 ];
Tc_error_10  = [ 7.399149e-01 ; 6.711670e-01 ; 6.720391e-01 ];

%-- Image #11:
omc_11 = [ 2.128547e-01 ; -3.019803e+00 ; -7.768522e-01 ];
Tc_11  = [ 2.054884e+02 ; -1.866566e+02 ; 7.111935e+02 ];
omc_error_11 = [ 5.110442e-04 ; 1.335573e-03 ; 1.912308e-03 ];
Tc_error_11  = [ 7.197943e-01 ; 6.729077e-01 ; 5.515558e-01 ];

%-- Image #12:
omc_12 = [ -1.906046e-01 ; 3.012094e+00 ; 7.376524e-01 ];
Tc_12  = [ 2.235250e+02 ; -1.374654e+02 ; 6.274029e+02 ];
omc_error_12 = [ 4.251899e-04 ; 1.245113e-03 ; 1.725777e-03 ];
Tc_error_12  = [ 6.287725e-01 ; 5.893411e-01 ; 4.770959e-01 ];

%-- Image #13:
omc_13 = [ -1.438074e-01 ; 2.933886e+00 ; 6.704769e-01 ];
Tc_13  = [ 2.226381e+02 ; -1.205987e+02 ; 5.972786e+02 ];
omc_error_13 = [ 4.213107e-04 ; 1.185475e-03 ; 1.613834e-03 ];
Tc_error_13  = [ 5.944944e-01 ; 5.569727e-01 ; 4.397600e-01 ];

%-- Image #14:
omc_14 = [ -1.224842e-01 ; 2.931371e+00 ; 6.289221e-01 ];
Tc_14  = [ 2.315793e+02 ; -1.192467e+02 ; 5.463022e+02 ];
omc_error_14 = [ 4.054885e-04 ; 1.146688e-03 ; 1.560038e-03 ];
Tc_error_14  = [ 5.440573e-01 ; 5.123011e-01 ; 4.145007e-01 ];

%-- Image #15:
omc_15 = [ -9.530502e-02 ; 2.905233e+00 ; 3.449247e-01 ];
Tc_15  = [ 1.518011e+02 ; -1.205972e+02 ; 5.536380e+02 ];
omc_error_15 = [ 3.167610e-04 ; 1.151302e-03 ; 1.594787e-03 ];
Tc_error_15  = [ 5.487588e-01 ; 5.063450e-01 ; 3.635904e-01 ];

%-- Image #16:
omc_16 = [ -3.296564e-01 ; 3.099264e+00 ; -2.750406e-01 ];
Tc_16  = [ 3.359683e+02 ; -9.485893e+01 ; 6.935472e+02 ];
omc_error_16 = [ 4.190154e-04 ; 1.454357e-03 ; 2.157000e-03 ];
Tc_error_16  = [ 6.872007e-01 ; 6.532162e-01 ; 5.404494e-01 ];

%-- Image #17:
omc_17 = [ 2.649136e-01 ; -2.772580e+00 ; -8.689021e-01 ];
Tc_17  = [ 2.098684e+02 ; -5.383407e+01 ; 4.332014e+02 ];
omc_error_17 = [ 5.835458e-04 ; 1.077884e-03 ; 1.376406e-03 ];
Tc_error_17  = [ 4.339125e-01 ; 4.100167e-01 ; 3.767805e-01 ];

%-- Image #18:
omc_18 = [ 2.760404e-01 ; -2.386233e+00 ; -1.128000e+00 ];
Tc_18  = [ 1.252386e+02 ; -2.270464e+01 ; 3.193016e+02 ];
omc_error_18 = [ 7.070831e-04 ; 1.055522e-03 ; 1.119507e-03 ];
Tc_error_18  = [ 3.201113e-01 ; 2.971639e-01 ; 2.978968e-01 ];

%-- Image #19:
omc_19 = [ 5.440562e-02 ; 2.335374e+00 ; 1.001798e+00 ];
Tc_19  = [ 1.902296e+02 ; -1.726223e+02 ; 5.152667e+02 ];
omc_error_19 = [ 6.590217e-04 ; 1.011286e-03 ; 1.105841e-03 ];
Tc_error_19  = [ 5.133015e-01 ; 4.770755e-01 ; 3.584349e-01 ];

%-- Image #20:
omc_20 = [ 1.821869e-01 ; 2.099404e+00 ; 6.584464e-01 ];
Tc_20  = [ 6.624607e+01 ; -2.193722e+02 ; 6.574455e+02 ];
omc_error_20 = [ 6.380437e-04 ; 9.810333e-04 ; 1.022281e-03 ];
Tc_error_20  = [ 6.543488e-01 ; 5.932326e-01 ; 3.744700e-01 ];

