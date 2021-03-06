#pragma once
#include "listener.h"

class PupilDiaTracker : public CWnd
{

public:
	PupilDiaTracker();
	virtual ~PupilDiaTracker();


	void InvalidateCtrl();
	void DrawPoint();
	void DrawTitle();
	double AppendPoint(double dia);
	void SetRange(double dLower, double dUpper, int nDecimalPlaces);
	void SetPlotColor(COLORREF rgb);
	int m_nShiftPixels;          // amount to shift with each new point 
	int m_nYDecimals;

private:

	CDC			m_dcGrid;
	CDC			m_dcPlot;
	CPen		m_penPlot;

	int m_nHalfShiftPixels;
	int m_nPlotShiftPixels;
	int m_nPlotHeight;
	int m_nPlotWidth;

	int			m_nClientWidth, m_nClientHeight;

	CBrush		m_brushBack;
	CRect		m_rectPlot;
	CRect		m_rectClient;

	CBitmap		m_bitmapGrid;
	CBitmap		m_bitmapPlot;

	CBitmap		*m_pbitmapOldGrid;
	CBitmap		*m_pbitmapOldPlot;

	double		m_dCurrentPosition;
	double		m_dPreviousPosition;  
	
	double		m_dRange;
	double		m_dVerticalFactor;

	double		m_dLowerLimit;        // lower bounds
	double		m_dUpperLimit;        // upper bounds


protected:

	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

};
