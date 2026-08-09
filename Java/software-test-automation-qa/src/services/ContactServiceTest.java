package services;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class ContactServiceTest {
    ContactService service;

    @BeforeEach
    void setUp() {
        service = new ContactService();
    }

    @Test
    void testAddContact() {
        Contact contact = new Contact("1", "John", "Doe", "1234567890", "Address");
        service.addContact(contact);
        assertEquals(1, service.getContactList().size());
    }
    
    @Test
    void testAddDuplicateId() {
        Contact contact1 = new Contact("1", "John", "Doe", "1234567890", "Address");
        Contact contact2 = new Contact("1", "Jane", "Doe", "0987654321", "Address 2");
        service.addContact(contact1);
        assertThrows(IllegalArgumentException.class, () -> service.addContact(contact2));
    }

    @Test
    void testUpdateContact() {
        Contact contact = new Contact("1", "John", "Doe", "1234567890", "Address");
        service.addContact(contact);
        service.updateContact("1", "Jane", "Smith", "0000000000", "New Address");
        
        assertEquals("Jane", service.getContactList().get(0).getFirstName());
        assertEquals("Smith", service.getContactList().get(0).getLastName());
    }
}