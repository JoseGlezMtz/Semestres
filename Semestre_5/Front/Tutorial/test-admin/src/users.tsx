import {useMediaQuery, Theme} from "@mui/material";
import {List, SimpleList, Datagrid, TextField, EmailField, TextInput, Create, SimpleForm, required}from "react-admin";

export const UserList= () =>{
    const isSmall= useMediaQuery<Theme>((theme) => theme.breakpoints.down("sm"));
    return(
    <List>
        {isSmall ? (
            <SimpleList
                primaryText={(record) => record.name}
                secondaryText={(record) => record.username}
                tertiaryText={(record)=> record.email}
                />
        ) :
            <Datagrid>
                <TextField source="id"/>
                <TextField source="name"/>
                <TextField source="username"/>
                <EmailField source="email"/>
                <TextField source="address.street"/>
                <TextField source="phone"/>
                <TextField source="website"/>
                <TextField source="company.name"/>
            </Datagrid>
            }
        </List>
    );
}

export const UserCreate= () =>(
    <Create>
        <SimpleForm>
            <TextInput source="id" validate={[required()]}/>
            <TextInput source="name"/>
            <TextInput source="username"/>
            <TextInput source="email"/>
            <TextInput source= "address.street"/>
            <TextInput source="phone"/>
            <TextInput source="website"/>
            <TextInput source="company.name"/>
        </SimpleForm>
    </Create>
);
