% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 657.390901675037750 ; 657.758500846827930 ];

%-- Principal point:
cc = [ 302.981276932563620 ; 242.617991816517760 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.255842324048049 ; 0.127556925582988 ; -0.000208539280591 ; 0.000033340104486 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 0.346743399537116 ; 0.370931671990451 ];

%-- Principal point uncertainty:
cc_error = [ 0.705119885700536 ; 0.645214915783219 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.002705344267533 ; 0.010752620006132 ; 0.000145715320927 ; 0.000143932217676 ; 0.000000000000000 ];

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
omc_1 = [ 2.354671e-03 ; 2.724029e+00 ; -1.293919e+00 ];
Tc_1  = [ 1.795771e+02 ; -6.485765e+01 ; 8.940421e+02 ];
omc_error_1 = [ 7.535397e-04 ; 1.276876e-03 ; 1.562982e-03 ];
Tc_error_1  = [ 9.597017e-01 ; 8.870644e-01 ; 4.729689e-01 ];

%-- Image #2:
omc_2 = [ -4.008291e-02 ; 2.915430e+00 ; -7.973573e-01 ];
Tc_2  = [ 2.023737e+02 ; -1.389233e+02 ; 7.962519e+02 ];
omc_error_2 = [ 5.505321e-04 ; 1.312991e-03 ; 1.803703e-03 ];
Tc_error_2  = [ 8.582136e-01 ; 7.920835e-01 ; 4.766462e-01 ];

%-- Image #3:
omc_3 = [ -2.637337e-01 ; 3.005766e+00 ; -8.188015e-01 ];
Tc_3  = [ 2.295958e+02 ; -1.148124e+02 ; 7.648143e+02 ];
omc_error_3 = [ 6.163730e-04 ; 1.290543e-03 ; 1.884975e-03 ];
Tc_error_3  = [ 8.241615e-01 ; 7.617428e-01 ; 4.926904e-01 ];

%-- Image #4:
omc_4 = [ 1.883943e-01 ; -2.572136e+00 ; 8.519952e-01 ];
Tc_4  = [ 2.601629e+02 ; -1.562982e+02 ; 6.234166e+02 ];
omc_error_4 = [ 5.550961e-04 ; 1.176145e-03 ; 1.493962e-03 ];
Tc_error_4  = [ 6.767255e-01 ; 6.336909e-01 ; 4.948802e-01 ];

%-- Image #5:
omc_5 = [ -6.578090e-01 ; 2.340922e+00 ; -1.057292e+00 ];
Tc_5  = [ 1.836756e+02 ; -1.316887e+01 ; 8.192187e+02 ];
omc_error_5 = [ 8.635042e-04 ; 1.062931e-03 ; 1.344868e-03 ];
Tc_error_5  = [ 8.841037e-01 ; 8.057045e-01 ; 4.245891e-01 ];

%-- Image #6:
omc_6 = [ -1.779525e-01 ; 2.840578e+00 ; 1.101068e+00 ];
Tc_6  = [ 2.072025e+02 ; -5.230730e+01 ; 4.901730e+02 ];
omc_error_6 = [ 6.526919e-04 ; 1.204531e-03 ; 1.548780e-03 ];
Tc_error_6  = [ 5.288398e-01 ; 4.957941e-01 ; 4.036687e-01 ];

%-- Image #7:
omc_7 = [ 3.935230e-02 ; 2.368056e+00 ; 7.253572e-01 ];
Tc_7  = [ 2.002811e+02 ; -1.525292e+02 ; 6.494492e+02 ];
omc_error_7 = [ 6.797794e-04 ; 1.134374e-03 ; 1.270546e-03 ];
Tc_error_7  = [ 6.983154e-01 ; 6.483382e-01 ; 4.477455e-01 ];

%-- Image #8:
omc_8 = [ 8.316188e-02 ; 2.294652e+00 ; 6.653481e-01 ];
Tc_8  = [ 9.230381e+01 ; -1.927372e+02 ; 6.918214e+02 ];
omc_error_8 = [ 6.370796e-04 ; 1.106567e-03 ; 1.245375e-03 ];
Tc_error_8  = [ 7.469771e-01 ; 6.821179e-01 ; 4.280222e-01 ];

%-- Image #9:
omc_9 = [ 4.393395e-01 ; -2.381861e+00 ; -4.174187e-01 ];
Tc_9  = [ 2.567569e+02 ; -7.582443e+01 ; 5.276243e+02 ];
omc_error_9 = [ 5.713387e-04 ; 1.227186e-03 ; 1.398200e-03 ];
Tc_error_9  = [ 6.014236e-01 ; 5.518611e-01 ; 5.560263e-01 ];

%-- Image #10:
omc_10 = [ 4.120680e-01 ; -2.586471e+00 ; -3.956860e-01 ];
Tc_10  = [ 2.711744e+02 ; -1.721264e+02 ; 7.095923e+02 ];
omc_error_10 = [ 5.242844e-04 ; 1.508051e-03 ; 1.855550e-03 ];
Tc_error_10  = [ 8.070945e-01 ; 7.318436e-01 ; 7.326579e-01 ];

%-- Image #11:
omc_11 = [ 2.126898e-01 ; -3.019679e+00 ; -7.768345e-01 ];
Tc_11  = [ 2.055663e+02 ; -1.865614e+02 ; 7.112347e+02 ];
omc_error_11 = [ 5.571361e-04 ; 1.455835e-03 ; 2.083691e-03 ];
Tc_error_11  = [ 7.848808e-01 ; 7.334915e-01 ; 6.011237e-01 ];

%-- Image #12:
omc_12 = [ -1.904313e-01 ; 3.012211e+00 ; 7.371727e-01 ];
Tc_12  = [ 2.236019e+02 ; -1.374183e+02 ; 6.275281e+02 ];
omc_error_12 = [ 4.634270e-04 ; 1.357811e-03 ; 1.881612e-03 ];
Tc_error_12  = [ 6.857174e-01 ; 6.424831e-01 ; 5.200926e-01 ];

%-- Image #13:
omc_13 = [ -1.436046e-01 ; 2.934081e+00 ; 6.700598e-01 ];
Tc_13  = [ 2.227110e+02 ; -1.205459e+02 ; 5.973378e+02 ];
omc_error_13 = [ 4.592551e-04 ; 1.292843e-03 ; 1.759688e-03 ];
Tc_error_13  = [ 6.482847e-01 ; 6.071408e-01 ; 4.793605e-01 ];

%-- Image #14:
omc_14 = [ -1.223221e-01 ; 2.931680e+00 ; 6.284416e-01 ];
Tc_14  = [ 2.316505e+02 ; -1.191939e+02 ; 5.463785e+02 ];
omc_error_14 = [ 4.419848e-04 ; 1.250527e-03 ; 1.701029e-03 ];
Tc_error_14  = [ 5.933111e-01 ; 5.584770e-01 ; 4.518090e-01 ];

%-- Image #15:
omc_15 = [ -9.524481e-02 ; 2.905645e+00 ; 3.443160e-01 ];
Tc_15  = [ 1.518909e+02 ; -1.205213e+02 ; 5.536657e+02 ];
omc_error_15 = [ 3.451230e-04 ; 1.254399e-03 ; 1.738470e-03 ];
Tc_error_15  = [ 5.983889e-01 ; 5.519688e-01 ; 3.963137e-01 ];

%-- Image #16:
omc_16 = [ -3.297028e-01 ; 3.099068e+00 ; -2.749911e-01 ];
Tc_16  = [ 3.360428e+02 ; -9.477293e+01 ; 6.935030e+02 ];
omc_error_16 = [ 4.563745e-04 ; 1.583467e-03 ; 2.348053e-03 ];
Tc_error_16  = [ 7.492317e-01 ; 7.119301e-01 ; 5.886621e-01 ];

%-- Image #17:
omc_17 = [ 2.647176e-01 ; -2.772704e+00 ; -8.683416e-01 ];
Tc_17  = [ 2.099167e+02 ; -5.384104e+01 ; 4.333667e+02 ];
omc_error_17 = [ 6.359687e-04 ; 1.175653e-03 ; 1.500629e-03 ];
Tc_error_17  = [ 4.732874e-01 ; 4.470674e-01 ; 4.107132e-01 ];

%-- Image #18:
omc_18 = [ 2.758792e-01 ; -2.386227e+00 ; -1.127710e+00 ];
Tc_18  = [ 1.252939e+02 ; -2.269913e+01 ; 3.194828e+02 ];
omc_error_18 = [ 7.707598e-04 ; 1.151194e-03 ; 1.220229e-03 ];
Tc_error_18  = [ 3.491974e-01 ; 3.240984e-01 ; 3.248887e-01 ];

%-- Image #19:
omc_19 = [ 5.464415e-02 ; 2.335587e+00 ; 1.001615e+00 ];
Tc_19  = [ 1.903129e+02 ; -1.726172e+02 ; 5.152811e+02 ];
omc_error_19 = [ 7.185475e-04 ; 1.102425e-03 ; 1.205372e-03 ];
Tc_error_19  = [ 5.597042e-01 ; 5.200316e-01 ; 3.906955e-01 ];

%-- Image #20:
omc_20 = [ 1.823221e-01 ; 2.099490e+00 ; 6.584685e-01 ];
Tc_20  = [ 6.639626e+01 ; -2.194263e+02 ; 6.572106e+02 ];
omc_error_20 = [ 6.955733e-04 ; 1.069229e-03 ; 1.114086e-03 ];
Tc_error_20  = [ 7.132263e-01 ; 6.463986e-01 ; 4.081151e-01 ];

