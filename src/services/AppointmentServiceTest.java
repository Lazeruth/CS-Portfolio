package services;

import static org.junit.jupiter.api.Assertions.*;
import java.util.Date;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class AppointmentServiceTest {
    AppointmentService service;

    @BeforeEach
    void setUp() {
        service = new AppointmentService();
    }

    @Test
    void testAddAppointment() {
        Date futureDate = new Date(new Date().getTime() + 100000);
        Appointment appt = new Appointment("1", futureDate, "Desc");
        service.addAppointment(appt);
        assertEquals(1, service.getAppointmentList().size());
    }

    @Test
    void testDeleteAppointment() {
        Date futureDate = new Date(new Date().getTime() + 100000);
        Appointment appt = new Appointment("1", futureDate, "Desc");
        service.addAppointment(appt);
        service.deleteAppointment("1");
        assertEquals(0, service.getAppointmentList().size());
    }
}