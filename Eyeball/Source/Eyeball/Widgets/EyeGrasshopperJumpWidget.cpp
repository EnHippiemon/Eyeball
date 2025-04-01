#include "EyeGrasshopperJumpWidget.h"

#include "Components/Image.h"

void UEyeGrasshopperJumpWidget::RenderJumpBar(const float Value) const
{
	JumpMeter->SetRenderScale(FVector2D(Value, 1));
	Frame->SetOpacity(Value != 0);
}