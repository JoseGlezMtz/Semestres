import {List,  Datagrid, TextField, ReferenceField, 
    EditButton, Edit, SimpleForm, TextInput, Create,  BooleanField, BooleanInput}from "react-admin";


export const TodosList= () =>(
    <List>
    <Datagrid>
        <ReferenceField source="userId" reference="users"/>
        <TextField source="id"/>
        <TextField source="title"/>
        <BooleanField source="completed"/>
        <EditButton/>
    </Datagrid>
    </List>
    );

export const TodosEdit= () =>(
    <Edit>
        <SimpleForm>
        <ReferenceField source="userId" reference="users"/>
        <TextInput source="id" InputProps = {{disabled: true}}/>
        <TextInput source="title"/>
        <BooleanInput source="completed"/>
        </SimpleForm>
    </Edit>
);

export const TodosCreate= () =>(
    <Create>
        <SimpleForm>
        <ReferenceField source="userId" reference="users"/>
        <TextInput source="id" />
        <TextInput source="title"/>
        <BooleanInput source="completed"/>
        </SimpleForm>
    </Create>)