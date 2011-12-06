package org.penghuang.tools.rotationlock;

import android.app.Activity;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.database.ContentObserver;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.provider.Settings.SettingNotFoundException;
import android.widget.Toast;


public class RotationLockActivity extends Activity {
    /**
     * Tag used for logging errors.
     */
    // private static final String LOG_TAG = "RL";
    
    private static final int RETRY_COUNT = 5;
    
    private static long mTime;
    
    private NotificationManager mNotificationManager;
    
    private boolean mLocked = false;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        mLocked = isPortraitOrientationLocked();

        mNotificationManager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
		
        // Listen system settings changes
        getApplicationContext().getContentResolver().registerContentObserver(
				android.provider.Settings.System.CONTENT_URI, true,
				new ContentObserver(null) {
					@Override
					public void onChange(boolean selfChange) {
						super.onChange(selfChange);
						systemSettingsChange();
					}
				});
    }

    @Override
    public void onStart() {
    	super.onStart();
		long time = System.currentTimeMillis();
		if (time > mTime + 1000) {
			mTime = time;
	        if (supportAccelerometerRotation())
	        	togglePortraitOrientationLock();
	        else {
				Toast.makeText(this, R.string.accelerometer_rotation_is_not_supported,
						Toast.LENGTH_SHORT).show();
	        }
		}
        moveTaskToBack(true);
    }
    
    @Override
    public void onDestroy() {
        mNotificationManager.cancelAll();
    	super.onDestroy();
    }
    
    // Check accelerometer.
	private boolean supportAccelerometerRotation() {
		SensorManager sensorManager = (SensorManager)getSystemService(SENSOR_SERVICE);
		if (sensorManager == null)
			return false;
		Sensor accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
		if (accelerometer == null)
			return false;
		
		try {
			android.provider.Settings.System.getInt(getContentResolver(),
					android.provider.Settings.System.ACCELEROMETER_ROTATION);
		} catch (SettingNotFoundException e) {
			return false;
		}
				
		return true;
	}
	
	// Show popup message.
	private void showPopupMessage(boolean locked) {
		int message = locked ? 
				R.string.portrait_orientation_locked : R.string.portrait_orientation_unlocked;
		Toast.makeText(this, message,
				Toast.LENGTH_SHORT).show();
	}
	
	// Show notification
	private void showNotification(boolean locked) {
		int message = locked ? 
				R.string.portrait_orientation_locked : R.string.portrait_orientation_unlocked;

		Notification notification = new Notification(
				locked ? R.drawable.ic_locked : R.drawable.ic_unlocked,
        		getText(message),
        		System.currentTimeMillis());
        PendingIntent contentIntent = PendingIntent.getActivity(this, 0,
                new Intent(this, RotationLockActivity.class), 0);
        notification.setLatestEventInfo((Context)this, 
        		getText(R.string.app_name), (CharSequence)getText(message), contentIntent);
        notification.flags |= Notification.FLAG_NO_CLEAR | Notification.FLAG_ONGOING_EVENT;
        notification.icon = locked ? R.drawable.ic_stat_locked : R.drawable.ic_stat_unlocked; 
        
        mNotificationManager.notify(R.string.app_name, notification);		
	}
	
	// Toggle portrait orientation lock setting.
	private boolean togglePortraitOrientationLock() {
		boolean locked = isPortraitOrientationLocked();

		for (int count = 0; count < RETRY_COUNT; count++) {
			setPortraitOrientationLock(!locked);
			if (isPortraitOrientationLocked() != locked) {
				showPopupMessage (!locked);
				return true;
			}
		}
		return false;
	}
	
	// Get system portrait orientation lock.
	private boolean isPortraitOrientationLocked() {
		int value = 1;
        try {
        	value = android.provider.Settings.System.getInt(getContentResolver(),
        			android.provider.Settings.System.ACCELEROMETER_ROTATION);
        } catch (SettingNotFoundException e) {
        	value = 1;
        }
        return value == 0;
	}
	
	// Set system portrait orientation lock.
	private void setPortraitOrientationLock(boolean lock) {
    	android.provider.Settings.System.putInt(getContentResolver(),
    			android.provider.Settings.System.ACCELEROMETER_ROTATION,
    			lock ? 0 : 1);		
	}
	
	// Handle system settings change.
	private void systemSettingsChange() {
		boolean locked = isPortraitOrientationLocked();
		if (mLocked != locked) {
			mLocked = locked;
			showNotification(locked);
		}
	}
 }