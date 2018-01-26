% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1341.462443662439000 ; 1337.777862511233900 ];

%-- Principal point:
cc = [ 676.708943451365490 ; 508.442913851370290 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.123608262430844 ; 0.136093565557737 ; 0.002771303662935 ; 0.002632659572608 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 4.176305305616153 ; 3.998684915539251 ];

%-- Principal point uncertainty:
cc_error = [ 7.169392405557274 ; 5.637549282337965 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.020144714462460 ; 0.156922019392992 ; 0.001118716483142 ; 0.001322256163466 ; 0.000000000000000 ];

%-- Image size:
nx = 1292;
ny = 964;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 90;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ -2.481763e+00 ; -1.640964e+00 ; 5.748088e-01 ];
Tc_1  = [ -1.430307e+02 ; 1.421165e+01 ; 9.238909e+02 ];
omc_error_1 = [ 6.157627e-03 ; 3.906862e-03 ; 1.094872e-02 ];
Tc_error_1  = [ 4.942360e+00 ; 3.898825e+00 ; 2.958597e+00 ];

%-- Image #2:
omc_2 = [ -2.110652e+00 ; -2.260119e+00 ; 1.189502e-01 ];
Tc_2  = [ -1.660255e+02 ; -9.646434e+01 ; 5.955105e+02 ];
omc_error_2 = [ 4.657135e-03 ; 4.918071e-03 ; 1.027410e-02 ];
Tc_error_2  = [ 3.193989e+00 ; 2.546355e+00 ; 2.369707e+00 ];

%-- Image #3:
omc_3 = [ 1.825856e+00 ; 1.719651e+00 ; -1.103829e+00 ];
Tc_3  = [ -1.251268e+02 ; -3.112617e+01 ; 7.062487e+02 ];
omc_error_3 = [ 3.227462e-03 ; 4.693349e-03 ; 6.908159e-03 ];
Tc_error_3  = [ 3.782670e+00 ; 2.989089e+00 ; 2.091066e+00 ];

%-- Image #4:
omc_4 = [ -2.336236e+00 ; -1.389580e+00 ; 1.062953e+00 ];
Tc_4  = [ -1.316851e+02 ; 2.682534e+01 ; 9.801801e+02 ];
omc_error_4 = [ 5.856776e-03 ; 2.919764e-03 ; 7.819156e-03 ];
Tc_error_4  = [ 5.257908e+00 ; 4.138591e+00 ; 2.924324e+00 ];

%-- Image #5:
omc_5 = [ -1.915358e+00 ; -2.077432e+00 ; 8.468315e-01 ];
Tc_5  = [ -4.333822e+01 ; -3.843755e+01 ; 9.536783e+02 ];
omc_error_5 = [ 5.081865e-03 ; 4.504222e-03 ; 8.528343e-03 ];
Tc_error_5  = [ 5.085691e+00 ; 4.012580e+00 ; 2.875024e+00 ];

%-- Image #6:
omc_6 = [ -1.775719e+00 ; -2.264921e+00 ; 5.007883e-01 ];
Tc_6  = [ -1.413295e+02 ; -8.888483e+01 ; 8.626254e+02 ];
omc_error_6 = [ 4.599310e-03 ; 5.343436e-03 ; 9.079195e-03 ];
Tc_error_6  = [ 4.610356e+00 ; 3.664106e+00 ; 2.901244e+00 ];

%-- Image #7:
omc_7 = [ 1.845644e+00 ; 1.926318e+00 ; -6.499257e-01 ];
Tc_7  = [ -1.394574e+02 ; -6.498620e+01 ; 6.925308e+02 ];
omc_error_7 = [ 3.091872e-03 ; 4.574243e-03 ; 7.474011e-03 ];
Tc_error_7  = [ 3.701060e+00 ; 2.934017e+00 ; 2.303762e+00 ];

%-- Image #8:
omc_8 = [ 1.988894e+00 ; 2.061424e+00 ; -1.836390e-02 ];
Tc_8  = [ -1.243304e+02 ; -2.493207e+00 ; 9.198753e+02 ];
omc_error_8 = [ 6.709338e-03 ; 6.664656e-03 ; 1.351935e-02 ];
Tc_error_8  = [ 4.925028e+00 ; 3.898957e+00 ; 3.772492e+00 ];

%-- Image #9:
omc_9 = [ 2.021042e+00 ; 2.015467e+00 ; 1.276599e-01 ];
Tc_9  = [ -1.291244e+02 ; -6.178379e+01 ; 8.777048e+02 ];
omc_error_9 = [ 5.844913e-03 ; 5.860481e-03 ; 1.165580e-02 ];
Tc_error_9  = [ 4.704227e+00 ; 3.716127e+00 ; 3.598066e+00 ];

%-- Image #10:
omc_10 = [ 1.781874e+00 ; 1.687830e+00 ; 4.421407e-01 ];
Tc_10  = [ -1.681139e+02 ; -9.571975e+01 ; 5.809427e+02 ];
omc_error_10 = [ 4.162372e-03 ; 4.060919e-03 ; 6.410479e-03 ];
Tc_error_10  = [ 3.160876e+00 ; 2.496323e+00 ; 2.448407e+00 ];

%-- Image #11:
omc_11 = [ 2.434090e+00 ; 1.516389e+00 ; -1.024742e+00 ];
Tc_11  = [ -1.480452e+02 ; 4.128275e+00 ; 7.933948e+02 ];
omc_error_11 = [ 3.747230e-03 ; 4.285275e-03 ; 8.494188e-03 ];
Tc_error_11  = [ 4.257913e+00 ; 3.354633e+00 ; 2.415890e+00 ];

%-- Image #12:
omc_12 = [ 1.560413e+00 ; 1.994388e+00 ; 3.867025e-01 ];
Tc_12  = [ -1.259187e+02 ; -6.299056e+01 ; 7.380641e+02 ];
omc_error_12 = [ 4.239357e-03 ; 4.604231e-03 ; 7.015151e-03 ];
Tc_error_12  = [ 3.953932e+00 ; 3.142911e+00 ; 2.934773e+00 ];

%-- Image #13:
omc_13 = [ -1.125795e+00 ; -2.353090e+00 ; 6.663698e-01 ];
Tc_13  = [ -6.574988e+01 ; -1.737772e+02 ; 8.476825e+02 ];
omc_error_13 = [ 3.914817e-03 ; 5.313474e-03 ; 6.799079e-03 ];
Tc_error_13  = [ 4.561212e+00 ; 3.592770e+00 ; 2.819626e+00 ];

%-- Image #14:
omc_14 = [ -2.000521e+00 ; -2.146607e+00 ; 4.769686e-01 ];
Tc_14  = [ -1.218445e+02 ; -1.126777e+02 ; 6.768306e+02 ];
omc_error_14 = [ 4.578541e-03 ; 4.181234e-03 ; 8.770677e-03 ];
Tc_error_14  = [ 3.630545e+00 ; 2.859213e+00 ; 2.305230e+00 ];

%-- Image #15:
omc_15 = [ 1.956561e+00 ; 2.191647e+00 ; -4.064302e-01 ];
Tc_15  = [ -1.395191e+02 ; -8.265742e+01 ; 6.537475e+02 ];
omc_error_15 = [ 3.716495e-03 ; 4.887578e-03 ; 9.047441e-03 ];
Tc_error_15  = [ 3.491269e+00 ; 2.769027e+00 ; 2.318411e+00 ];

%-- Image #16:
omc_16 = [ -2.070899e+00 ; -2.176395e+00 ; -1.687089e-01 ];
Tc_16  = [ -1.347642e+02 ; -1.035717e+02 ; 4.905442e+02 ];
omc_error_16 = [ 3.579827e-03 ; 4.451700e-03 ; 8.351213e-03 ];
Tc_error_16  = [ 2.656491e+00 ; 2.110503e+00 ; 1.999824e+00 ];

%-- Image #17:
omc_17 = [ 1.887912e+00 ; 2.242005e+00 ; -1.265016e-01 ];
Tc_17  = [ -1.366155e+02 ; -1.201157e+02 ; 7.291383e+02 ];
omc_error_17 = [ 4.628275e-03 ; 6.069153e-03 ; 1.092599e-02 ];
Tc_error_17  = [ 3.910912e+00 ; 3.088679e+00 ; 2.767079e+00 ];

%-- Image #18:
omc_18 = [ -1.975611e+00 ; -1.518506e+00 ; 6.099411e-01 ];
Tc_18  = [ -1.745463e+02 ; -4.414316e+01 ; 6.289802e+02 ];
omc_error_18 = [ 4.494654e-03 ; 3.556887e-03 ; 6.581092e-03 ];
Tc_error_18  = [ 3.382091e+00 ; 2.677509e+00 ; 1.991995e+00 ];

%-- Image #19:
omc_19 = [ 1.576175e+00 ; 1.833916e+00 ; -2.899363e-01 ];
Tc_19  = [ -1.345956e+02 ; -1.047568e+02 ; 6.662715e+02 ];
omc_error_19 = [ 3.189466e-03 ; 4.692445e-03 ; 6.455931e-03 ];
Tc_error_19  = [ 3.564131e+00 ; 2.823584e+00 ; 2.400944e+00 ];

%-- Image #20:
omc_20 = [ 2.135724e+00 ; 2.158116e+00 ; 7.094379e-01 ];
Tc_20  = [ -1.522963e+02 ; -6.754322e+01 ; 8.318931e+02 ];
omc_error_20 = [ 6.067538e-03 ; 4.326480e-03 ; 9.946477e-03 ];
Tc_error_20  = [ 4.480194e+00 ; 3.547127e+00 ; 3.574805e+00 ];

%-- Image #21:
omc_21 = [ 1.916088e+00 ; 1.945209e+00 ; -4.003808e-01 ];
Tc_21  = [ -1.438858e+02 ; -9.360379e+01 ; 6.313483e+02 ];
omc_error_21 = [ 3.310205e-03 ; 4.498128e-03 ; 7.747346e-03 ];
Tc_error_21  = [ 3.382321e+00 ; 2.675711e+00 ; 2.269952e+00 ];

%-- Image #22:
omc_22 = [ 1.363253e+00 ; 1.684420e+00 ; -1.922617e-01 ];
Tc_22  = [ -1.450232e+02 ; -1.052999e+02 ; 6.819676e+02 ];
omc_error_22 = [ 3.282570e-03 ; 4.806228e-03 ; 5.612069e-03 ];
Tc_error_22  = [ 3.648787e+00 ; 2.895437e+00 ; 2.509760e+00 ];

%-- Image #23:
omc_23 = [ -2.047767e+00 ; -2.071013e+00 ; 3.371516e-01 ];
Tc_23  = [ -1.158331e+02 ; -7.756447e+01 ; 6.362456e+02 ];
omc_error_23 = [ 4.268273e-03 ; 4.459957e-03 ; 8.728248e-03 ];
Tc_error_23  = [ 3.394986e+00 ; 2.681861e+00 ; 2.203933e+00 ];

%-- Image #24:
omc_24 = [ 2.143412e+00 ; 2.192627e+00 ; -2.115154e-01 ];
Tc_24  = [ -1.083950e+02 ; -6.971969e+01 ; 8.684517e+02 ];
omc_error_24 = [ 7.935786e-03 ; 7.735121e-03 ; 1.669669e-02 ];
Tc_error_24  = [ 4.646680e+00 ; 3.661013e+00 ; 3.293267e+00 ];

%-- Image #25:
omc_25 = [ NaN ; NaN ; NaN ];
Tc_25  = [ NaN ; NaN ; NaN ];
omc_error_25 = [ NaN ; NaN ; NaN ];
Tc_error_25  = [ NaN ; NaN ; NaN ];

%-- Image #26:
omc_26 = [ -1.724263e+00 ; -1.748018e+00 ; 1.074288e+00 ];
Tc_26  = [ -1.006348e+02 ; -8.444995e+01 ; 7.612678e+02 ];
omc_error_26 = [ 5.138961e-03 ; 3.730821e-03 ; 6.239170e-03 ];
Tc_error_26  = [ 4.089200e+00 ; 3.223291e+00 ; 2.132230e+00 ];

%-- Image #27:
omc_27 = [ 1.847692e+00 ; 1.754058e+00 ; 2.601733e-01 ];
Tc_27  = [ -1.622339e+02 ; -9.368332e+01 ; 5.903668e+02 ];
omc_error_27 = [ 4.031707e-03 ; 4.150565e-03 ; 6.847600e-03 ];
Tc_error_27  = [ 3.194240e+00 ; 2.525600e+00 ; 2.411467e+00 ];

%-- Image #28:
omc_28 = [ 1.820713e+00 ; 1.718340e+00 ; -1.046350e+00 ];
Tc_28  = [ -1.278958e+02 ; -9.103025e+00 ; 7.297927e+02 ];
omc_error_28 = [ 3.194820e-03 ; 4.611656e-03 ; 6.894069e-03 ];
Tc_error_28  = [ 3.901772e+00 ; 3.087940e+00 ; 2.187709e+00 ];

%-- Image #29:
omc_29 = [ NaN ; NaN ; NaN ];
Tc_29  = [ NaN ; NaN ; NaN ];
omc_error_29 = [ NaN ; NaN ; NaN ];
Tc_error_29  = [ NaN ; NaN ; NaN ];

%-- Image #30:
omc_30 = [ NaN ; NaN ; NaN ];
Tc_30  = [ NaN ; NaN ; NaN ];
omc_error_30 = [ NaN ; NaN ; NaN ];
Tc_error_30  = [ NaN ; NaN ; NaN ];

%-- Image #31:
omc_31 = [ NaN ; NaN ; NaN ];
Tc_31  = [ NaN ; NaN ; NaN ];
omc_error_31 = [ NaN ; NaN ; NaN ];
Tc_error_31  = [ NaN ; NaN ; NaN ];

%-- Image #32:
omc_32 = [ NaN ; NaN ; NaN ];
Tc_32  = [ NaN ; NaN ; NaN ];
omc_error_32 = [ NaN ; NaN ; NaN ];
Tc_error_32  = [ NaN ; NaN ; NaN ];

%-- Image #33:
omc_33 = [ NaN ; NaN ; NaN ];
Tc_33  = [ NaN ; NaN ; NaN ];
omc_error_33 = [ NaN ; NaN ; NaN ];
Tc_error_33  = [ NaN ; NaN ; NaN ];

%-- Image #34:
omc_34 = [ NaN ; NaN ; NaN ];
Tc_34  = [ NaN ; NaN ; NaN ];
omc_error_34 = [ NaN ; NaN ; NaN ];
Tc_error_34  = [ NaN ; NaN ; NaN ];

%-- Image #35:
omc_35 = [ NaN ; NaN ; NaN ];
Tc_35  = [ NaN ; NaN ; NaN ];
omc_error_35 = [ NaN ; NaN ; NaN ];
Tc_error_35  = [ NaN ; NaN ; NaN ];

%-- Image #36:
omc_36 = [ NaN ; NaN ; NaN ];
Tc_36  = [ NaN ; NaN ; NaN ];
omc_error_36 = [ NaN ; NaN ; NaN ];
Tc_error_36  = [ NaN ; NaN ; NaN ];

%-- Image #37:
omc_37 = [ NaN ; NaN ; NaN ];
Tc_37  = [ NaN ; NaN ; NaN ];
omc_error_37 = [ NaN ; NaN ; NaN ];
Tc_error_37  = [ NaN ; NaN ; NaN ];

%-- Image #38:
omc_38 = [ NaN ; NaN ; NaN ];
Tc_38  = [ NaN ; NaN ; NaN ];
omc_error_38 = [ NaN ; NaN ; NaN ];
Tc_error_38  = [ NaN ; NaN ; NaN ];

%-- Image #39:
omc_39 = [ NaN ; NaN ; NaN ];
Tc_39  = [ NaN ; NaN ; NaN ];
omc_error_39 = [ NaN ; NaN ; NaN ];
Tc_error_39  = [ NaN ; NaN ; NaN ];

%-- Image #40:
omc_40 = [ NaN ; NaN ; NaN ];
Tc_40  = [ NaN ; NaN ; NaN ];
omc_error_40 = [ NaN ; NaN ; NaN ];
Tc_error_40  = [ NaN ; NaN ; NaN ];

%-- Image #41:
omc_41 = [ NaN ; NaN ; NaN ];
Tc_41  = [ NaN ; NaN ; NaN ];
omc_error_41 = [ NaN ; NaN ; NaN ];
Tc_error_41  = [ NaN ; NaN ; NaN ];

%-- Image #42:
omc_42 = [ NaN ; NaN ; NaN ];
Tc_42  = [ NaN ; NaN ; NaN ];
omc_error_42 = [ NaN ; NaN ; NaN ];
Tc_error_42  = [ NaN ; NaN ; NaN ];

%-- Image #43:
omc_43 = [ NaN ; NaN ; NaN ];
Tc_43  = [ NaN ; NaN ; NaN ];
omc_error_43 = [ NaN ; NaN ; NaN ];
Tc_error_43  = [ NaN ; NaN ; NaN ];

%-- Image #44:
omc_44 = [ NaN ; NaN ; NaN ];
Tc_44  = [ NaN ; NaN ; NaN ];
omc_error_44 = [ NaN ; NaN ; NaN ];
Tc_error_44  = [ NaN ; NaN ; NaN ];

%-- Image #45:
omc_45 = [ NaN ; NaN ; NaN ];
Tc_45  = [ NaN ; NaN ; NaN ];
omc_error_45 = [ NaN ; NaN ; NaN ];
Tc_error_45  = [ NaN ; NaN ; NaN ];

%-- Image #46:
omc_46 = [ NaN ; NaN ; NaN ];
Tc_46  = [ NaN ; NaN ; NaN ];
omc_error_46 = [ NaN ; NaN ; NaN ];
Tc_error_46  = [ NaN ; NaN ; NaN ];

%-- Image #47:
omc_47 = [ NaN ; NaN ; NaN ];
Tc_47  = [ NaN ; NaN ; NaN ];
omc_error_47 = [ NaN ; NaN ; NaN ];
Tc_error_47  = [ NaN ; NaN ; NaN ];

%-- Image #48:
omc_48 = [ NaN ; NaN ; NaN ];
Tc_48  = [ NaN ; NaN ; NaN ];
omc_error_48 = [ NaN ; NaN ; NaN ];
Tc_error_48  = [ NaN ; NaN ; NaN ];

%-- Image #49:
omc_49 = [ NaN ; NaN ; NaN ];
Tc_49  = [ NaN ; NaN ; NaN ];
omc_error_49 = [ NaN ; NaN ; NaN ];
Tc_error_49  = [ NaN ; NaN ; NaN ];

%-- Image #50:
omc_50 = [ NaN ; NaN ; NaN ];
Tc_50  = [ NaN ; NaN ; NaN ];
omc_error_50 = [ NaN ; NaN ; NaN ];
Tc_error_50  = [ NaN ; NaN ; NaN ];

%-- Image #51:
omc_51 = [ NaN ; NaN ; NaN ];
Tc_51  = [ NaN ; NaN ; NaN ];
omc_error_51 = [ NaN ; NaN ; NaN ];
Tc_error_51  = [ NaN ; NaN ; NaN ];

%-- Image #52:
omc_52 = [ NaN ; NaN ; NaN ];
Tc_52  = [ NaN ; NaN ; NaN ];
omc_error_52 = [ NaN ; NaN ; NaN ];
Tc_error_52  = [ NaN ; NaN ; NaN ];

%-- Image #53:
omc_53 = [ NaN ; NaN ; NaN ];
Tc_53  = [ NaN ; NaN ; NaN ];
omc_error_53 = [ NaN ; NaN ; NaN ];
Tc_error_53  = [ NaN ; NaN ; NaN ];

%-- Image #54:
omc_54 = [ NaN ; NaN ; NaN ];
Tc_54  = [ NaN ; NaN ; NaN ];
omc_error_54 = [ NaN ; NaN ; NaN ];
Tc_error_54  = [ NaN ; NaN ; NaN ];

%-- Image #55:
omc_55 = [ NaN ; NaN ; NaN ];
Tc_55  = [ NaN ; NaN ; NaN ];
omc_error_55 = [ NaN ; NaN ; NaN ];
Tc_error_55  = [ NaN ; NaN ; NaN ];

%-- Image #56:
omc_56 = [ NaN ; NaN ; NaN ];
Tc_56  = [ NaN ; NaN ; NaN ];
omc_error_56 = [ NaN ; NaN ; NaN ];
Tc_error_56  = [ NaN ; NaN ; NaN ];

%-- Image #57:
omc_57 = [ NaN ; NaN ; NaN ];
Tc_57  = [ NaN ; NaN ; NaN ];
omc_error_57 = [ NaN ; NaN ; NaN ];
Tc_error_57  = [ NaN ; NaN ; NaN ];

%-- Image #58:
omc_58 = [ NaN ; NaN ; NaN ];
Tc_58  = [ NaN ; NaN ; NaN ];
omc_error_58 = [ NaN ; NaN ; NaN ];
Tc_error_58  = [ NaN ; NaN ; NaN ];

%-- Image #59:
omc_59 = [ NaN ; NaN ; NaN ];
Tc_59  = [ NaN ; NaN ; NaN ];
omc_error_59 = [ NaN ; NaN ; NaN ];
Tc_error_59  = [ NaN ; NaN ; NaN ];

%-- Image #60:
omc_60 = [ NaN ; NaN ; NaN ];
Tc_60  = [ NaN ; NaN ; NaN ];
omc_error_60 = [ NaN ; NaN ; NaN ];
Tc_error_60  = [ NaN ; NaN ; NaN ];

%-- Image #61:
omc_61 = [ NaN ; NaN ; NaN ];
Tc_61  = [ NaN ; NaN ; NaN ];
omc_error_61 = [ NaN ; NaN ; NaN ];
Tc_error_61  = [ NaN ; NaN ; NaN ];

%-- Image #62:
omc_62 = [ NaN ; NaN ; NaN ];
Tc_62  = [ NaN ; NaN ; NaN ];
omc_error_62 = [ NaN ; NaN ; NaN ];
Tc_error_62  = [ NaN ; NaN ; NaN ];

%-- Image #63:
omc_63 = [ NaN ; NaN ; NaN ];
Tc_63  = [ NaN ; NaN ; NaN ];
omc_error_63 = [ NaN ; NaN ; NaN ];
Tc_error_63  = [ NaN ; NaN ; NaN ];

%-- Image #64:
omc_64 = [ NaN ; NaN ; NaN ];
Tc_64  = [ NaN ; NaN ; NaN ];
omc_error_64 = [ NaN ; NaN ; NaN ];
Tc_error_64  = [ NaN ; NaN ; NaN ];

%-- Image #65:
omc_65 = [ NaN ; NaN ; NaN ];
Tc_65  = [ NaN ; NaN ; NaN ];
omc_error_65 = [ NaN ; NaN ; NaN ];
Tc_error_65  = [ NaN ; NaN ; NaN ];

%-- Image #66:
omc_66 = [ NaN ; NaN ; NaN ];
Tc_66  = [ NaN ; NaN ; NaN ];
omc_error_66 = [ NaN ; NaN ; NaN ];
Tc_error_66  = [ NaN ; NaN ; NaN ];

%-- Image #67:
omc_67 = [ NaN ; NaN ; NaN ];
Tc_67  = [ NaN ; NaN ; NaN ];
omc_error_67 = [ NaN ; NaN ; NaN ];
Tc_error_67  = [ NaN ; NaN ; NaN ];

%-- Image #68:
omc_68 = [ NaN ; NaN ; NaN ];
Tc_68  = [ NaN ; NaN ; NaN ];
omc_error_68 = [ NaN ; NaN ; NaN ];
Tc_error_68  = [ NaN ; NaN ; NaN ];

%-- Image #69:
omc_69 = [ NaN ; NaN ; NaN ];
Tc_69  = [ NaN ; NaN ; NaN ];
omc_error_69 = [ NaN ; NaN ; NaN ];
Tc_error_69  = [ NaN ; NaN ; NaN ];

%-- Image #70:
omc_70 = [ NaN ; NaN ; NaN ];
Tc_70  = [ NaN ; NaN ; NaN ];
omc_error_70 = [ NaN ; NaN ; NaN ];
Tc_error_70  = [ NaN ; NaN ; NaN ];

%-- Image #71:
omc_71 = [ NaN ; NaN ; NaN ];
Tc_71  = [ NaN ; NaN ; NaN ];
omc_error_71 = [ NaN ; NaN ; NaN ];
Tc_error_71  = [ NaN ; NaN ; NaN ];

%-- Image #72:
omc_72 = [ NaN ; NaN ; NaN ];
Tc_72  = [ NaN ; NaN ; NaN ];
omc_error_72 = [ NaN ; NaN ; NaN ];
Tc_error_72  = [ NaN ; NaN ; NaN ];

%-- Image #73:
omc_73 = [ NaN ; NaN ; NaN ];
Tc_73  = [ NaN ; NaN ; NaN ];
omc_error_73 = [ NaN ; NaN ; NaN ];
Tc_error_73  = [ NaN ; NaN ; NaN ];

%-- Image #74:
omc_74 = [ NaN ; NaN ; NaN ];
Tc_74  = [ NaN ; NaN ; NaN ];
omc_error_74 = [ NaN ; NaN ; NaN ];
Tc_error_74  = [ NaN ; NaN ; NaN ];

%-- Image #75:
omc_75 = [ NaN ; NaN ; NaN ];
Tc_75  = [ NaN ; NaN ; NaN ];
omc_error_75 = [ NaN ; NaN ; NaN ];
Tc_error_75  = [ NaN ; NaN ; NaN ];

%-- Image #76:
omc_76 = [ NaN ; NaN ; NaN ];
Tc_76  = [ NaN ; NaN ; NaN ];
omc_error_76 = [ NaN ; NaN ; NaN ];
Tc_error_76  = [ NaN ; NaN ; NaN ];

%-- Image #77:
omc_77 = [ NaN ; NaN ; NaN ];
Tc_77  = [ NaN ; NaN ; NaN ];
omc_error_77 = [ NaN ; NaN ; NaN ];
Tc_error_77  = [ NaN ; NaN ; NaN ];

%-- Image #78:
omc_78 = [ NaN ; NaN ; NaN ];
Tc_78  = [ NaN ; NaN ; NaN ];
omc_error_78 = [ NaN ; NaN ; NaN ];
Tc_error_78  = [ NaN ; NaN ; NaN ];

%-- Image #79:
omc_79 = [ NaN ; NaN ; NaN ];
Tc_79  = [ NaN ; NaN ; NaN ];
omc_error_79 = [ NaN ; NaN ; NaN ];
Tc_error_79  = [ NaN ; NaN ; NaN ];

%-- Image #80:
omc_80 = [ NaN ; NaN ; NaN ];
Tc_80  = [ NaN ; NaN ; NaN ];
omc_error_80 = [ NaN ; NaN ; NaN ];
Tc_error_80  = [ NaN ; NaN ; NaN ];

%-- Image #81:
omc_81 = [ NaN ; NaN ; NaN ];
Tc_81  = [ NaN ; NaN ; NaN ];
omc_error_81 = [ NaN ; NaN ; NaN ];
Tc_error_81  = [ NaN ; NaN ; NaN ];

%-- Image #82:
omc_82 = [ NaN ; NaN ; NaN ];
Tc_82  = [ NaN ; NaN ; NaN ];
omc_error_82 = [ NaN ; NaN ; NaN ];
Tc_error_82  = [ NaN ; NaN ; NaN ];

%-- Image #83:
omc_83 = [ NaN ; NaN ; NaN ];
Tc_83  = [ NaN ; NaN ; NaN ];
omc_error_83 = [ NaN ; NaN ; NaN ];
Tc_error_83  = [ NaN ; NaN ; NaN ];

%-- Image #84:
omc_84 = [ NaN ; NaN ; NaN ];
Tc_84  = [ NaN ; NaN ; NaN ];
omc_error_84 = [ NaN ; NaN ; NaN ];
Tc_error_84  = [ NaN ; NaN ; NaN ];

%-- Image #85:
omc_85 = [ NaN ; NaN ; NaN ];
Tc_85  = [ NaN ; NaN ; NaN ];
omc_error_85 = [ NaN ; NaN ; NaN ];
Tc_error_85  = [ NaN ; NaN ; NaN ];

%-- Image #86:
omc_86 = [ NaN ; NaN ; NaN ];
Tc_86  = [ NaN ; NaN ; NaN ];
omc_error_86 = [ NaN ; NaN ; NaN ];
Tc_error_86  = [ NaN ; NaN ; NaN ];

%-- Image #87:
omc_87 = [ NaN ; NaN ; NaN ];
Tc_87  = [ NaN ; NaN ; NaN ];
omc_error_87 = [ NaN ; NaN ; NaN ];
Tc_error_87  = [ NaN ; NaN ; NaN ];

%-- Image #88:
omc_88 = [ NaN ; NaN ; NaN ];
Tc_88  = [ NaN ; NaN ; NaN ];
omc_error_88 = [ NaN ; NaN ; NaN ];
Tc_error_88  = [ NaN ; NaN ; NaN ];

%-- Image #89:
omc_89 = [ NaN ; NaN ; NaN ];
Tc_89  = [ NaN ; NaN ; NaN ];
omc_error_89 = [ NaN ; NaN ; NaN ];
Tc_error_89  = [ NaN ; NaN ; NaN ];

%-- Image #90:
omc_90 = [ NaN ; NaN ; NaN ];
Tc_90  = [ NaN ; NaN ; NaN ];
omc_error_90 = [ NaN ; NaN ; NaN ];
Tc_error_90  = [ NaN ; NaN ; NaN ];

