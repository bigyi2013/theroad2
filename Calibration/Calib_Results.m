% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 657.220781333487930 ; 657.736402880360970 ];

%-- Principal point:
cc = [ 303.180864120713240 ; 240.144170251533300 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.260869901956120 ; 0.155787253515510 ; -0.000597689804861 ; -0.000150851555457 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 1.219714877395011 ; 0.902454458853346 ];

%-- Principal point uncertainty:
cc_error = [ 1.600585972635177 ; 2.081601086100332 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.007297038079619 ; 0.032486823747482 ; 0.000485967483607 ; 0.000370835454526 ; 0.000000000000000 ];

%-- Image size:
nx = 640;
ny = 480;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 10;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ -1.794812e+00 ; -2.066733e+00 ; -4.774421e-01 ];
Tc_1  = [ -1.512589e+02 ; -2.325832e+02 ; 7.050297e+02 ];
omc_error_1 = [ 1.460667e-03 ; 2.085159e-03 ; 3.372622e-03 ];
Tc_error_1  = [ 1.762285e+00 ; 2.447451e+00 ; 1.493809e+00 ];

%-- Image #2:
omc_2 = [ NaN ; NaN ; NaN ];
Tc_2  = [ NaN ; NaN ; NaN ];
omc_error_2 = [ NaN ; NaN ; NaN ];
Tc_error_2  = [ NaN ; NaN ; NaN ];

%-- Image #3:
omc_3 = [ NaN ; NaN ; NaN ];
Tc_3  = [ NaN ; NaN ; NaN ];
omc_error_3 = [ NaN ; NaN ; NaN ];
Tc_error_3  = [ NaN ; NaN ; NaN ];

%-- Image #4:
omc_4 = [ NaN ; NaN ; NaN ];
Tc_4  = [ NaN ; NaN ; NaN ];
omc_error_4 = [ NaN ; NaN ; NaN ];
Tc_error_4  = [ NaN ; NaN ; NaN ];

%-- Image #5:
omc_5 = [ NaN ; NaN ; NaN ];
Tc_5  = [ NaN ; NaN ; NaN ];
omc_error_5 = [ NaN ; NaN ; NaN ];
Tc_error_5  = [ NaN ; NaN ; NaN ];

%-- Image #6:
omc_6 = [ NaN ; NaN ; NaN ];
Tc_6  = [ NaN ; NaN ; NaN ];
omc_error_6 = [ NaN ; NaN ; NaN ];
Tc_error_6  = [ NaN ; NaN ; NaN ];

%-- Image #7:
omc_7 = [ -1.615054e+00 ; -1.955213e+00 ; -3.442284e-01 ];
Tc_7  = [ -1.353711e+02 ; -1.370717e+02 ; 4.903971e+02 ];
omc_error_7 = [ 1.765331e-03 ; 2.248696e-03 ; 3.205206e-03 ];
Tc_error_7  = [ 1.198941e+00 ; 1.645123e+00 ; 9.482886e-01 ];

%-- Image #8:
omc_8 = [ NaN ; NaN ; NaN ];
Tc_8  = [ NaN ; NaN ; NaN ];
omc_error_8 = [ NaN ; NaN ; NaN ];
Tc_error_8  = [ NaN ; NaN ; NaN ];

%-- Image #9:
omc_9 = [ NaN ; NaN ; NaN ];
Tc_9  = [ NaN ; NaN ; NaN ];
omc_error_9 = [ NaN ; NaN ; NaN ];
Tc_error_9  = [ NaN ; NaN ; NaN ];

%-- Image #10:
omc_10 = [ 1.893992e+00 ; 1.594509e+00 ; 1.468283e+00 ];
Tc_10  = [ -1.439612e+02 ; -8.647132e+01 ; 3.963100e+02 ];
omc_error_10 = [ 2.775981e-03 ; 2.079489e-03 ; 3.821056e-03 ];
Tc_error_10  = [ 1.013901e+00 ; 1.298187e+00 ; 8.419029e-01 ];

