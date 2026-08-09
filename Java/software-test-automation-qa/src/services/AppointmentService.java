package services;

import java.util.ArrayList;
import java.util.List;

public class AppointmentService {
    private List<Appointment> appointments = new ArrayList<>();

    public void addAppointment(Appointment newAppointment) {
        for (Appointment a : appointments) {
            if (a.getAppointmentId().equals(newAppointment.getAppointmentId())) {
                throw new IllegalArgumentException("Appointment ID already exists");
            }
        }
        appointments.add(newAppointment);
    }

    public void deleteAppointment(String appointmentId) {
        for (Appointment a : appointments) {
            if (a.getAppointmentId().equals(appointmentId)) {
                appointments.remove(a);
                return;
            }
        }
        throw new IllegalArgumentException("Appointment ID not found");
    }
    
    public List<Appointment> getAppointmentList() { return appointments; }
}
