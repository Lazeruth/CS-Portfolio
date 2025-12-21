package services;

import java.util.ArrayList;
import java.util.List;

public class ContactService {
    private List<Contact> contacts = new ArrayList<>();

    public void addContact(Contact newContact) {
        for (Contact c : contacts) {
            if (c.getContactId().equals(newContact.getContactId())) {
                throw new IllegalArgumentException("Contact ID already exists");
            }
        }
        contacts.add(newContact);
    }

    public void deleteContact(String contactId) {
        contacts.removeIf(c -> c.getContactId().equals(contactId));
    }

    public void updateContact(String contactId, String newFirstName, String newLastName, String newPhone, String newAddress) {
        for (Contact c : contacts) {
            if (c.getContactId().equals(contactId)) {
                if (newFirstName != null) c.setFirstName(newFirstName);
                if (newLastName != null) c.setLastName(newLastName);
                if (newPhone != null) c.setPhone(newPhone);
                if (newAddress != null) c.setAddress(newAddress);
                return;
            }
        }
        throw new IllegalArgumentException("Contact ID not found");
    }
    
    // Helper for testing
    public List<Contact> getContactList() { return contacts; }
}