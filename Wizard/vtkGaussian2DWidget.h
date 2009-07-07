/*=========================================================================

  Module:    $RCSfile: vtkGaussian2DWidget.h,v $
  Author:    $Sylvain Jaume (MIT)$

=========================================================================*/
// .NAME vtkGaussian2DWidget - a render widget
// .SECTION Description
// This class encapsulates a render window, a renderer and several other
// objects inside a single widget. Actors and props can be added,
// annotations can be set.
// .WARNING
// This widget set the camera to be in parallel projection mode.
// You can change this default (after Create()) by calling:
// renderwidget->GetRenderer()->GetActiveCamera()->ParallelProjectionOff();

#ifndef __vtkGaussian2DWidget_h
#define __vtkGaussian2DWidget_h

#include "vtkKWRenderWidget.h"

class vtkDoubleArray;

class KWWidgets_EXPORT vtkGaussian2DWidget : public vtkKWRenderWidget
{
public:
  static vtkGaussian2DWidget* New();
  vtkTypeRevisionMacro(vtkGaussian2DWidget, vtkKWCompositeWidget);

  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Define the range of intensities in image 1 (X axis)
  vtkSetVector2Macro(XAxisRange, double);
  vtkGetVector2Macro(XAxisRange, double);

  // Description:
  // Define the range of intensities in image 2 (Y axis)
  vtkSetVector2Macro(YAxisRange, double);
  vtkGetVector2Macro(YAxisRange, double);

  // Description:
  // Set the mean and standard deviation to define an additional
  // gaussian distribution
  void AddGaussian(double meanX, double meanY, double sigma2,
      double rgb[3]);

  // Description:
  // Create the gaussians.
  virtual void CreateGaussian2D();

protected:
  vtkGaussian2DWidget();
  ~vtkGaussian2DWidget();

  double XAxisRange[2];
  double YAxisRange[2];

  vtkDoubleArray *MeanXArray;
  vtkDoubleArray *MeanYArray;
  vtkDoubleArray *Sigma2Array;

  vtkDoubleArray *RGBArray;

private:
  vtkGaussian2DWidget(const vtkGaussian2DWidget&);  // Not implemented
  void operator=(const vtkGaussian2DWidget&);  // Not implemented
};

#endif
