package services;

import java.util.Date;

public class Appointment {
    private final String appointmentId;
    private final Date appointmentDate;
    private final String description;

    public Appointment(String appointmentId, Date appointmentDate, String description) {
        if (appointmentId == null || appointmentId.length() > 10) {
            throw new IllegalArgumentException("Invalid ID");
        }
        if (appointmentDate == null || appointmentDate.before(new Date())) {
            throw new IllegalArgumentException("Invalid Date");
        }
        if (description == null || description.length() > 50) {
            throw new IllegalArgumentException("Invalid Description");
        }
        this.appointmentId = appointmentId;
        this.appointmentDate = appointmentDate;
        this.description = description;
    }

    public String getAppointmentId() { return appointmentId; }
    public Date getAppointmentDate() { return appointmentDate; }
    public String getDescription() { return description; }
}