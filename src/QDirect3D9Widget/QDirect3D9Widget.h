/*
 *
 */

#pragma once


#include <QWidget>
#include <QTimer>

#include <d3d9.h>

class QDirect3D9Widget : public QWidget
{
	Q_OBJECT

public:
	QDirect3D9Widget(QWidget * parent);
	~QDirect3D9Widget();

	void release();
	void resetEnvironment();

private:
	bool init();
	void tick();
	void render();

	
// Qt Events
private:
	bool event(QEvent * event) override;
	void showEvent(QShowEvent * event) override;
	QPaintEngine * paintEngine() const override;
	void paintEvent(QPaintEvent * event) override;
	void resizeEvent(QResizeEvent * event) override;

	LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#if QT_VERSION >= 0x050000
	bool nativeEvent(const QByteArray & eventType, void * message, long * result) override;
#else
	bool winEvent(MSG * message, long * result) override;
#endif


Q_SIGNALS:
	void deviceInitialized(bool success);

	void eventHandled();
	void widgetResized();

	void ticked();
	void rendered();


private Q_SLOTS:
	void onFrame();
	void onReset();

// Getters / Setters
public:
	HWND const & nativeHandle() const { return m_hWnd; }

	LPDIRECT3DDEVICE9 device() const { return m_lpD3DDev; }
	D3DPRESENT_PARAMETERS * devicePresentParams() { return &m_DevParam; }
	D3DCAPS9 * deviceCapabilities() { return &m_DevCaps; }
	LPDIRECT3D9 direct3D() const { return m_lpD3D; }



private:
	LPDIRECT3DDEVICE9        m_lpD3DDev;
	D3DPRESENT_PARAMETERS    m_DevParam;
	D3DCAPS9                 m_DevCaps;
	LPDIRECT3D9              m_lpD3D;


	QTimer                    m_qTimer;

	HWND                      m_hWnd;
	bool                      m_bDeviceInitialized;

};
