import {List,  Datagrid, TextField, ReferenceField, 
    EditButton, Edit, SimpleForm, TextInput, Create}from "react-admin";


export const PostList= () =>(
    <List>
    <Datagrid>

        <TextField source="id"/>
        <ReferenceField source="userId" reference="users"/>
        <TextField source="title"/>
        <TextField source="body"/>
        <EditButton/>
        
        
    </Datagrid>
    </List>
    );

export const PostEdit= () =>(
    <Edit>
        <SimpleForm>
            <TextInput source="id" InputProps = {{disabled: true}}/>
            <ReferenceField source="userId" reference="users"/>
            <TextInput source="title"/>
            <TextInput source="body"/>
        </SimpleForm>
    </Edit>
);

export const PostCreate= () =>(
    <Create>
        <SimpleForm>
            <ReferenceField source="userId" reference="users"/>
            <TextInput source="title"/>
            <TextInput source="body" multiline rows={5}/>
        </SimpleForm>
    </Create>)