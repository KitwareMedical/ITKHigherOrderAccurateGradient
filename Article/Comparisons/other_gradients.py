#!/usr/bin/env python

import itk

input = '../../Testing/Data/Input/foot.mha'

valt = itk.F
imgt = itk.Image[valt, 2]

reader = itk.ImageFileReader[imgt].New( FileName=input )

grad_io = itk.VTKImageIO.New()
grad_io.SetPixelType( grad_io.VECTOR )

gradient_filter = itk.GradientImageFilter[ imgt, valt, valt ].New()
gradient_filter.SetInput( reader.GetOutput() )
gradt = itk.output(gradient_filter)
itk.write( gradient_filter, 'foot_GradientImageFilter.mha' )

gradient_mag_filter = itk.GradientToMagnitudeImageFilter[ gradt, imgt ].New()
gradient_mag_filter.SetInput( gradient_filter.GetOutput() )
itk.write( gradient_mag_filter, 'foot_GradientImageFilter_magnitude.mha' )


dog_filter = itk.DifferenceOfGaussiansGradientImageFilter[ imgt, valt ].New()
dog_filter.SetInput( reader.GetOutput() )
dog_filter.SetWidth( 1 )
itk.write( dog_filter, 'foot_DifferenceOfGaussiansGradientImageFilter.mha' )

dog_mag_filter = itk.GradientToMagnitudeImageFilter[ gradt, imgt ].New()
dog_mag_filter.SetInput( dog_filter.GetOutput() )
itk.write( dog_mag_filter, 'foot_DifferenceOfGaussiansGradientImageFilter_magnitude.mha' )


recursive_gauss_filter = itk.GradientRecursiveGaussianImageFilter[ imgt, gradt ].New()
recursive_gauss_filter.SetInput( reader.GetOutput() )
recursive_gauss_filter.SetSigma( 1.0 )
recursive_gauss_filter.SetNormalizeAcrossScale( True )
itk.write( recursive_gauss_filter, 'foot_GradientRecursiveGaussianImageFilter.mha' )

recursive_gauss_mag_filter = itk.GradientToMagnitudeImageFilter[ gradt, imgt ].New()
recursive_gauss_mag_filter.SetInput( recursive_gauss_filter )
itk.write( recursive_gauss_mag_filter, 'foot_GradientRecursiveGaussianImageFilter_magnitude.mha' )
