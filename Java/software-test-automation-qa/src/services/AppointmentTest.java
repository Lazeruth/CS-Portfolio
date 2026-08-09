package services;

import static org.junit.jupiter.api.Assertions.*;
import java.util.Date;
import org.junit.jupiter.api.Test;

class AppointmentTest {

    @Test
    void testAppointment() {
        Date futureDate = new Date(new Date().getTime() + 100000);
        Appointment appt = new Appointment("12345", futureDate, "Desc");
        assertEquals("12345", appt.getAppointmentId());
    }

    @Test
    void testAppointmentDateInPast() {
        Date pastDate = new Date(new Date().getTime() - 100000);
        assertThrows(IllegalArgumentException.class, () -> {
            new Appointment("12345", pastDate, "Desc");
        });
    }
}