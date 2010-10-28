set( INPUT_DIR ${ITK_HIGHER_ORDER_ACCURATE_GRADIENT_SOURCE_DIR}/Testing/Data/Input )

add_executable( itkHigherOrderAccurateGradientImageFilterTest
  itkHigherOrderAccurateGradientImageFilterTest.cxx
  )
target_link_libraries( itkHigherOrderAccurateGradientImageFilterTest
  ITKCommon
  ITKIO
  )

# @todo compare components
add_test( itkHigherOrderAccurateGradientImageFilterTest
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/itkHigherOrderAccurateGradientImageFilterTest
  itkHigherOrderAccurateGradientImageFilterTest
  ${INPUT_DIR}/foot.mha
  itkHigherOrderAccurateGradientImageFilterTest
  )


add_executable( itkHigherOrderAccurateDerivativeImageFilterTest
  itkHigherOrderAccurateDerivativeImageFilterTest.cxx
  )
target_link_libraries( itkHigherOrderAccurateDerivativeImageFilterTest
  ITKCommon
  ITKIO
  )

# @todo compare output of regular with accuracy of 1
add_test( itkHigherOrderAccurateDerivativeImageFilterTest
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/itkHigherOrderAccurateDerivativeImageFilterTest
  itkHigherOrderAccurateDerivativeImageFilterTest
  ${INPUT_DIR}/foot.mha
  itkHigherOrderAccurateDerivativeImageFilterTest
  )
