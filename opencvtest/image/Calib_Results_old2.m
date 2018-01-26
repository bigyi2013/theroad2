% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1338.225413409964400 ; 1334.561042314494000 ];

%-- Principal point:
cc = [ 674.451810841757490 ; 506.324362030297950 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.128721012832991 ; 0.148521437859489 ; 0.002911255174826 ; 0.002404785892195 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 3.953107794849425 ; 3.783917496962453 ];

%-- Principal point uncertainty:
cc_error = [ 6.794944074119062 ; 5.355200305634125 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.018865581185455 ; 0.145041231485443 ; 0.001053791210093 ; 0.001239276089692 ; 0.000000000000000 ];

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
omc_1 = [ -2.480967e+00 ; -1.640231e+00 ; 5.816734e-01 ];
Tc_1  = [ -1.413213e+02 ; 1.565451e+01 ; 9.223643e+02 ];
omc_error_1 = [ 5.847307e-03 ; 3.712507e-03 ; 1.038004e-02 ];
Tc_error_1  = [ 4.688140e+00 ; 3.705691e+00 ; 2.799836e+00 ];

%-- Image #2:
omc_2 = [ -2.111283e+00 ; -2.260708e+00 ; 1.199489e-01 ];
Tc_2  = [ -1.650509e+02 ; -9.555911e+01 ; 5.940837e+02 ];
omc_error_2 = [ 4.418481e-03 ; 4.678187e-03 ; 9.769706e-03 ];
Tc_error_2  = [ 3.027101e+00 ; 2.418376e+00 ; 2.245350e+00 ];

%-- Image #3:
omc_3 = [ 1.824299e+00 ; 1.719121e+00 ; -1.107403e+00 ];
Tc_3  = [ -1.239112e+02 ; -2.998894e+01 ; 7.050483e+02 ];
omc_error_3 = [ 3.076574e-03 ; 4.462344e-03 ; 6.563739e-03 ];
Tc_error_3  = [ 3.587706e+00 ; 2.840620e+00 ; 1.978693e+00 ];

%-- Image #4:
omc_4 = [ -2.335917e+00 ; -1.388593e+00 ; 1.067064e+00 ];
Tc_4  = [ -1.299806e+02 ; 2.833684e+01 ; 9.783655e+02 ];
omc_error_4 = [ 5.570573e-03 ; 2.781504e-03 ; 7.430469e-03 ];
Tc_error_4  = [ 4.986387e+00 ; 3.932736e+00 ; 2.768027e+00 ];

%-- Image #5:
omc_5 = [ -1.914505e+00 ; -2.076679e+00 ; 8.533201e-01 ];
Tc_5  = [ -4.159821e+01 ; -3.687954e+01 ; 9.520648e+02 ];
omc_error_5 = [ 4.834292e-03 ; 4.280836e-03 ; 8.098525e-03 ];
Tc_error_5  = [ 4.823638e+00 ; 3.814040e+00 ; 2.721949e+00 ];

%-- Image #6:
omc_6 = [ -1.775816e+00 ; -2.264616e+00 ; 5.048833e-01 ];
Tc_6  = [ -1.399350e+02 ; -8.755722e+01 ; 8.612648e+02 ];
omc_error_6 = [ 4.373454e-03 ; 5.086403e-03 ; 8.633366e-03 ];
Tc_error_6  = [ 4.373118e+00 ; 3.482770e+00 ; 2.747707e+00 ];

%-- Image #7:
omc_7 = [ 1.844664e+00 ; 1.926141e+00 ; -6.541356e-01 ];
Tc_7  = [ -1.383050e+02 ; -6.386027e+01 ; 6.913574e+02 ];
omc_error_7 = [ 2.947653e-03 ; 4.348688e-03 ; 7.103715e-03 ];
Tc_error_7  = [ 3.510171e+00 ; 2.788372e+00 ; 2.180781e+00 ];

%-- Image #8:
omc_8 = [ 1.988800e+00 ; 2.061633e+00 ; -2.084847e-02 ];
Tc_8  = [ -1.228317e+02 ; -1.080408e+00 ; 9.179760e+02 ];
omc_error_8 = [ 6.395518e-03 ; 6.334139e-03 ; 1.286310e-02 ];
Tc_error_8  = [ 4.669500e+00 ; 3.704783e+00 ; 3.578065e+00 ];

%-- Image #9:
omc_9 = [ 2.022266e+00 ; 2.017459e+00 ; 1.258986e-01 ];
Tc_9  = [ -1.276710e+02 ; -6.043871e+01 ; 8.759480e+02 ];
omc_error_9 = [ 5.586649e-03 ; 5.582760e-03 ; 1.113083e-02 ];
Tc_error_9  = [ 4.460224e+00 ; 3.531028e+00 ; 3.414066e+00 ];

%-- Image #10:
omc_10 = [ 1.781632e+00 ; 1.688804e+00 ; 4.389260e-01 ];
Tc_10  = [ -1.671716e+02 ; -9.483007e+01 ; 5.797265e+02 ];
omc_error_10 = [ 3.959387e-03 ; 3.857991e-03 ; 6.102872e-03 ];
Tc_error_10  = [ 2.996512e+00 ; 2.371470e+00 ; 2.319611e+00 ];

%-- Image #11:
omc_11 = [ 2.432709e+00 ; 1.515138e+00 ; -1.029321e+00 ];
Tc_11  = [ -1.466240e+02 ; 5.398061e+00 ; 7.919183e+02 ];
omc_error_11 = [ 3.567314e-03 ; 4.075248e-03 ; 8.068397e-03 ];
Tc_error_11  = [ 4.038031e+00 ; 3.187520e+00 ; 2.285804e+00 ];

%-- Image #12:
omc_12 = [ 1.560517e+00 ; 1.995261e+00 ; 3.844891e-01 ];
Tc_12  = [ -1.246746e+02 ; -6.187080e+01 ; 7.361035e+02 ];
omc_error_12 = [ 4.033215e-03 ; 4.372734e-03 ; 6.680416e-03 ];
Tc_error_12  = [ 3.746312e+00 ; 2.984428e+00 ; 2.779943e+00 ];

%-- Image #13:
omc_13 = [ -1.125687e+00 ; -2.351817e+00 ; 6.679852e-01 ];
Tc_13  = [ -6.442975e+01 ; -1.725676e+02 ; 8.460043e+02 ];
omc_error_13 = [ 3.719836e-03 ; 5.055077e-03 ; 6.465130e-03 ];
Tc_error_13  = [ 4.324479e+00 ; 3.413772e+00 ; 2.671669e+00 ];

%-- Image #14:
omc_14 = [ -2.000380e+00 ; -2.146111e+00 ; 4.799355e-01 ];
Tc_14  = [ -1.207503e+02 ; -1.116527e+02 ; 6.755889e+02 ];
omc_error_14 = [ 4.351295e-03 ; 3.979925e-03 ; 8.337190e-03 ];
Tc_error_14  = [ 3.442805e+00 ; 2.716879e+00 ; 2.183422e+00 ];

%-- Image #15:
omc_15 = [ 1.955931e+00 ; 2.191135e+00 ; -4.101488e-01 ];
Tc_15  = [ -1.384559e+02 ; -8.163517e+01 ; 6.525286e+02 ];
omc_error_15 = [ 3.539140e-03 ; 4.643237e-03 ; 8.595744e-03 ];
Tc_error_15  = [ 3.310494e+00 ; 2.631100e+00 ; 2.195523e+00 ];

%-- Image #16:
omc_16 = [ -2.071331e+00 ; -2.176266e+00 ; -1.663135e-01 ];
Tc_16  = [ -1.339487e+02 ; -1.027682e+02 ; 4.894169e+02 ];
omc_error_16 = [ 3.393999e-03 ; 4.229247e-03 ; 7.934410e-03 ];
Tc_error_16  = [ 2.517874e+00 ; 2.004691e+00 ; 1.894201e+00 ];

%-- Image #17:
omc_17 = [ 1.888532e+00 ; 2.242947e+00 ; -1.283019e-01 ];
Tc_17  = [ -1.354295e+02 ; -1.190184e+02 ; 7.275611e+02 ];
omc_error_17 = [ 4.422046e-03 ; 5.777943e-03 ; 1.041212e-02 ];
Tc_error_17  = [ 3.707292e+00 ; 2.934305e+00 ; 2.622986e+00 ];

%-- Image #18:
omc_18 = [ -1.976246e+00 ; -1.517686e+00 ; 6.130460e-01 ];
Tc_18  = [ -1.735143e+02 ; -4.312125e+01 ; 6.280943e+02 ];
omc_error_18 = [ 4.272257e-03 ; 3.382055e-03 ; 6.257294e-03 ];
Tc_error_18  = [ 3.208753e+00 ; 2.545015e+00 ; 1.885762e+00 ];

%-- Image #19:
omc_19 = [ 1.575232e+00 ; 1.832757e+00 ; -2.903867e-01 ];
Tc_19  = [ -1.336050e+02 ; -1.037594e+02 ; 6.646611e+02 ];
omc_error_19 = [ 3.043105e-03 ; 4.458272e-03 ; 6.135578e-03 ];
Tc_error_19  = [ 3.377726e+00 ; 2.681780e+00 ; 2.274122e+00 ];

%-- Image #20:
omc_20 = [ 2.135363e+00 ; 2.156674e+00 ; 7.104980e-01 ];
Tc_20  = [ -1.506582e+02 ; -6.618678e+01 ; 8.286294e+02 ];
omc_error_20 = [ 5.763479e-03 ; 4.092467e-03 ; 9.438612e-03 ];
Tc_error_20  = [ 4.239575e+00 ; 3.363503e+00 ; 3.383011e+00 ];

%-- Image #21:
omc_21 = [ 1.915460e+00 ; 1.945280e+00 ; -4.032784e-01 ];
Tc_21  = [ -1.428428e+02 ; -9.263656e+01 ; 6.301283e+02 ];
omc_error_21 = [ 3.156996e-03 ; 4.276271e-03 ; 7.364882e-03 ];
Tc_error_21  = [ 3.206980e+00 ; 2.542306e+00 ; 2.149578e+00 ];

%-- Image #22:
omc_22 = [ 1.362311e+00 ; 1.684926e+00 ; -1.942717e-01 ];
Tc_22  = [ -1.439049e+02 ; -1.042699e+02 ; 6.805512e+02 ];
omc_error_22 = [ 3.127502e-03 ; 4.565988e-03 ; 5.338451e-03 ];
Tc_error_22  = [ 3.459072e+00 ; 2.750960e+00 ; 2.376921e+00 ];

%-- Image #23:
omc_23 = [ -2.047819e+00 ; -2.070460e+00 ; 3.391936e-01 ];
Tc_23  = [ -1.148099e+02 ; -7.657747e+01 ; 6.349485e+02 ];
omc_error_23 = [ 4.053286e-03 ; 4.246093e-03 ; 8.297383e-03 ];
Tc_error_23  = [ 3.218705e+00 ; 2.548026e+00 ; 2.087715e+00 ];

%-- Image #24:
omc_24 = [ 2.142870e+00 ; 2.191698e+00 ; -2.204013e-01 ];
Tc_24  = [ -1.069686e+02 ; -6.830777e+01 ; 8.674448e+02 ];
omc_error_24 = [ 7.521681e-03 ; 7.312366e-03 ; 1.578553e-02 ];
Tc_error_24  = [ 4.409294e+00 ; 3.481425e+00 ; 3.113791e+00 ];

%-- Image #25:
omc_25 = [ NaN ; NaN ; NaN ];
Tc_25  = [ NaN ; NaN ; NaN ];
omc_error_25 = [ NaN ; NaN ; NaN ];
Tc_error_25  = [ NaN ; NaN ; NaN ];

%-- Image #26:
omc_26 = [ -1.723718e+00 ; -1.746523e+00 ; 1.077727e+00 ];
Tc_26  = [ -9.931577e+01 ; -8.323126e+01 ; 7.600866e+02 ];
omc_error_26 = [ 4.885864e-03 ; 3.549962e-03 ; 5.929283e-03 ];
Tc_error_26  = [ 3.878832e+00 ; 3.063695e+00 ; 2.018132e+00 ];

%-- Image #27:
omc_27 = [ 1.847403e+00 ; 1.754647e+00 ; 2.571231e-01 ];
Tc_27  = [ -1.612540e+02 ; -9.277706e+01 ; 5.891440e+02 ];
omc_error_27 = [ 3.838054e-03 ; 3.943748e-03 ; 6.517011e-03 ];
Tc_error_27  = [ 3.028168e+00 ; 2.399368e+00 ; 2.284494e+00 ];

%-- Image #28:
omc_28 = [ 1.819045e+00 ; 1.717585e+00 ; -1.050389e+00 ];
Tc_28  = [ -1.266395e+02 ; -7.883037e+00 ; 7.284831e+02 ];
omc_error_28 = [ 3.045678e-03 ; 4.384551e-03 ; 6.549873e-03 ];
Tc_error_28  = [ 3.700404e+00 ; 2.934371e+00 ; 2.069876e+00 ];

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

