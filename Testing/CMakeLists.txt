set( INPUT_DIR ${ITK_SECOND_ORDER_GRADIENT_SOURCE_DIR}/Testing/Data/Input )

add_executable( itkSecondOrderGradientImageFilterTest
  itkSecondOrderGradientImageFilterTest.cxx
  )
target_link_libraries( itkSecondOrderGradientImageFilterTest
  ITKCommon
  ITKIO
  )

# @todo compare components
add_test( itkSecondOrderGradientImageFilterTest
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/itkSecondOrderGradientImageFilterTest
  itkSecondOrderGradientImageFilterTest
  ${INPUT_DIR}/foot.mha
  itkSecondOrderGradientImageFilterTest
  )
