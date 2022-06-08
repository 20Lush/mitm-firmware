#include <hidboot.h>
#include <usbhub.h>
#include <HID.h>
#include <Mouse.h>
#include <SPI.h>

class udef_MRP : public MouseReportParser
{
    public:
        int dx;
        int dy;
        int dz;
        void ParseButtons();
        void InitButtons();

    private:
        bool lmb;
        bool rmb;
        bool mmb;
        bool fmb;
        bool bmb;

    protected:
        void OnMouseMove	        (MOUSEINFO *mi);
        void OnLeftButtonUp	        (MOUSEINFO *mi);
        void OnLeftButtonDown	    (MOUSEINFO *mi);
        void OnRightButtonUp	    (MOUSEINFO *mi);
        void OnRightButtonDown	    (MOUSEINFO *mi);
        void OnMiddleButtonUp	    (MOUSEINFO *mi);
        void OnMiddleButtonDown	    (MOUSEINFO *mi);
        void OnForwardButtonUp	    (MOUSEINFO *mi);
        void OnForwardButtonDown    (MOUSEINFO *mi);
        void OnBackwardButtonUp	    (MOUSEINFO *mi);
        void OnBackwardButtonDown   (MOUSEINFO *mi);
        
};

void udef_MRP::OnMouseMove(MOUSEINFO *mi){
    dx = mi->dX;
    dy = mi->dY;
    dz = mi->dZ;
    Serial.print("dx=");
    Serial.print(dx, DEC);
    Serial.print(" dy=");
    Serial.println(dx, DEC);
};

void udef_MRP::OnLeftButtonUp	(MOUSEINFO *mi){
    lmb = false;
    Serial.println("L Butt Up");
};

void udef_MRP::OnLeftButtonDown	(MOUSEINFO *mi){
    lmb = true;
    Serial.println("L Butt Dn");
};

void udef_MRP::OnRightButtonUp	(MOUSEINFO *mi){
    rmb = false;
    Serial.println("R Butt Up");
};

void udef_MRP::OnRightButtonDown	(MOUSEINFO *mi){
    rmb = true;
    Serial.println("R Butt Dn");
};

void udef_MRP::OnMiddleButtonUp	(MOUSEINFO *mi){
    mmb = false;
    Serial.println("M Butt Up");
};

void udef_MRP::OnMiddleButtonDown	(MOUSEINFO *mi){
    mmb = true;
    Serial.println("M Butt Dn");
};

void udef_MRP::OnForwardButtonUp	(MOUSEINFO *mi){
    fmb  = true;
    Serial.println("fwd Butt Up");
};

void udef_MRP::OnForwardButtonDown	(MOUSEINFO *mi){
    fmb  = false;
    Serial.println("fwd Butt Dn");
};

void udef_MRP::OnBackwardButtonUp	(MOUSEINFO *mi){
    bmb = true;
    Serial.println("bkwd Butt Up");
};

void udef_MRP::OnBackwardButtonDown	(MOUSEINFO *mi){
    bmb = false;
    Serial.println("bkwd Butt Dn");
};

void udef_MRP::ParseButtons(){
    if(lmb)
        Mouse.press(MOUSE_LEFT);
    else if(!lmb)
        Mouse.release(MOUSE_LEFT);
    if(rmb)
        Mouse.press(MOUSE_RIGHT);
    else if(!rmb)
        Mouse.release(MOUSE_RIGHT);
    if(mmb)
        Mouse.press(MOUSE_MIDDLE);
    else if(!mmb)
        Mouse.release(MOUSE_MIDDLE);
    // if(fmb)
    //     Mouse.press(MOUSE_FORWARD);
    // else if(!fmb)
    //     Mouse.release(MOUSE_FORWARD);
    // if(bmb)
    //     Mouse.press(MOUSE_BACKWARD);
    // else if(!bmb)
    //     Mouse.release(MOUSE_BACKWARD);
}

void udef_MRP::InitButtons(){
    lmb = false;
    rmb = false;
    mmb = false;
    fmb = false;
    bmb = false;
}
